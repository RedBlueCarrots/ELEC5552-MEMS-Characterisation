----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:56:05 09/06/2026 
-- Design Name: 
-- Module Name:    BigLookUp - structural 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity BigLookUp is
    Port ( m_clk : in  STD_LOGIC;
           clk_out : out  STD_LOGIC;
           dac_out : out  STD_LOGIC_VECTOR (13 downto 0);
           wvfrm_sel : in  STD_LOGIC_VECTOR (1 downto 0);
           qual_sel : in  STD_LOGIC_VECTOR (1 downto 0);
			  addr_out : out STD_LOGIC_VECTOR(10 DOWNTO 0));
end BigLookUp;

architecture rtl of BigLookUp is

	component Block_Lookup
		PORT (
			clka	: IN STD_LOGIC;
			addra : IN STD_LOGIC_VECTOR(10 DOWNTO 0);
         douta : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
      );
	end component;
		
	signal counter : STD_LOGIC_VECTOR(6 DOWNTO 0) := "0000000";
	signal addr : STD_LOGIC_VECTOR(10 DOWNTO 0);
	signal ram_out : STD_LOGIC_VECTOR(15 DOWNTO 0);
	signal wvfrm_choose : STD_LOGIC_VECTOR(3 DOWNTO 0);
	signal wvfrm_select : STD_LOGIC_VECTOR(3 DOWNTO 0);

begin
	block_instance : Block_Lookup port map ( clka => m_clk, addra => addr, douta => ram_out ); 
	dac_out <= ram_out(13 downto 0);
	wvfrm_choose <= "0001" when (wvfrm_sel = "00") else
						 "0010" when (wvfrm_sel = "01") else
						 "0100" when (wvfrm_sel = "10") else
						 "1000";
	wvfrm_select <= "0001" when (wvfrm_sel = "00") else
						 "0011" when (wvfrm_sel = "01") else
						 "0111" when (wvfrm_sel = "10") else
						 "1111";
	addr <= "0"&qual_sel & ((wvfrm_choose OR("0"&counter(6 downto 4))) AND wvfrm_select) & counter(3 downto 0);
	addr_out <= addr;
	clk_out <= m_clk;
	process (m_clk)
   begin       
        if rising_edge(m_clk) then
            if counter(3 downto 0) = "1001" then
                counter(3 downto 0) <= "0000";
					 counter(6 downto 4) <= std_logic_vector(unsigned(counter(6 downto 4)) + 1);
            else
                counter(3 downto 0) <= std_logic_vector(unsigned(counter(3 downto 0)) + 1);
            end if;
				
				
        end if;
    end process;

end rtl;

