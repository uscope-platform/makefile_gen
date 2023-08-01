library ieee;
use IEEE.std_logic_1164.all;

entity half_adder is
  port (
    i_bit1  : in std_logic;
    i_bit2  : in std_logic;
    --
    o_sum   : out std_logic;
    o_carry : out std_logic
    );
end half_adder;

architecture rtl of half_adder is

    component ANDGATE is
      port (
        I1 : in std_logic;
        I2 : in std_logic;
        O  : out std_logic);
    end component ANDGATE;

begin
    o_sum   <= i_bit1 xor i_bit2;
    and_component : ANDGATE
    port map (
      I1  => i_bit1,
      I2  => i_bit2,
      O => o_carry
    );

end rtl;