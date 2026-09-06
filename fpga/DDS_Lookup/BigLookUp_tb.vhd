--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:    16:17:58 09/06/2026
-- Design Name:   
-- Module Name:    /home/redbluecarrots/Documents/University/ELEC5552/ELEC5552-MEMS-Characterisation/fpga/DDS_Lookup/BigLookUp_tb.vhd
-- Project Name:  DDS_Lookup
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: BigLookUp
-- 
--------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

-- Standard File I/O libraries
use STD.TEXTIO.ALL;
use IEEE.STD_LOGIC_TEXTIO.ALL;

entity BigLookUp_tb is
-- Testbench entities have no ports
end BigLookUp_tb;

architecture behavior of BigLookUp_tb is 

    -- Unit Under Test (UUT) Component Declaration
    component BigLookUp
        Port ( 
            m_clk     : in  STD_LOGIC;
            clk_out   : out STD_LOGIC;
            dac_out   : out STD_LOGIC_VECTOR (13 downto 0);
            wvfrm_sel : in  STD_LOGIC_VECTOR (1 downto 0);
            qual_sel  : in  STD_LOGIC_VECTOR (1 downto 0);
            addr_out  : out STD_LOGIC_VECTOR(10 downto 0)
        );
    end component;

    -- Inputs
    signal m_clk     : std_logic := '0';
    signal wvfrm_sel : std_logic_vector(1 downto 0) := "00";
    signal qual_sel  : std_logic_vector(1 downto 0) := "00";

    -- Outputs
    signal clk_out   : std_logic;
    signal dac_out   : std_logic_vector(13 downto 0);
    signal addr_out  : std_logic_vector(10 downto 0);

    -- Clock Period Definition (50 MHz clock -> 20 ns period)
    constant m_clk_period : time := 20 ns;

    -- Output File Handle
    file csv_file : text open write_mode is "dac_output.csv";

begin

    -- Instantiate the Unit Under Test (UUT)
    uut: BigLookUp PORT MAP (
          m_clk     => m_clk,
          clk_out   => clk_out,
          dac_out   => dac_out,
          wvfrm_sel => wvfrm_sel,
          qual_sel  => qual_sel,
          addr_out  => addr_out
        );

    -- Clock Generation Process
    m_clk_process :process
    begin
        m_clk <= '0';
        wait for m_clk_period/2;
        m_clk <= '1';
        wait for m_clk_period/2;
    end process;

    -- Stimulus Process
    stim_proc: process
    begin        
        -- Hold reset state for 100 ns
        wait for 100 ns;    

        -- Test Case 1: Default configuration (wvfrm_sel = "00", qual_sel = "00")
        wait for m_clk_period * 20;

        -- Test Case 2: Change waveform selection to "01"
        wvfrm_sel <= "01";
        wait for m_clk_period * 20;

        -- Test Case 3: Change waveform selection to "10" and quality to "01"
        wvfrm_sel <= "10";
        qual_sel  <= "01";
        wait for m_clk_period * 40;

        -- Test Case 4: Change waveform selection to "11" and quality to "11"
        wvfrm_sel <= "11";
        qual_sel  <= "11";
        wait for m_clk_period * 160;

        -- End Simulation
        assert false report "Simulation complete. Output exported to dac_output.csv" severity note;
        wait;
    end process;

    -- CSV Writer Process
    file_writer_proc: process(m_clk)
        variable line_buf : line;
        variable header   : boolean := true;
    begin
        if rising_edge(m_clk) then
            -- Write CSV header on the very first clock cycle
            if header then
                write(line_buf, string'("Time_ns,wvfrm_sel,qual_sel,addr_out_hex,dac_out_hex,dac_out_dec"));
                writeline(csv_file, line_buf);
                header := false;
            end if;

            -- Write data columns
            write(line_buf, now / 1 ns);
            write(line_buf, string'(","));
            write(line_buf, wvfrm_sel);
            write(line_buf, string'(","));
            write(line_buf, qual_sel);
            write(line_buf, string'(","));
            hwrite(line_buf, addr_out);
            write(line_buf, string'(","));
            hwrite(line_buf, dac_out);
            write(line_buf, string'(","));
            write(line_buf, to_integer(unsigned(dac_out)));

            -- Flush line buffer to dac_output.csv
            writeline(csv_file, line_buf);
        end if;
    end process;

end behavior;