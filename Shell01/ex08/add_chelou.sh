NBR1=$(echo "$FT_NBR1" | tr \'\\\\\"\?\! '01234')
NBR2=$(echo "$FT_NBR2" | tr mrdoc '01234')
SOMME=$(echo "obase=13; ibase=5; $NBR1 + $NBR2" | bc)
echo $SOMME | tr [:upper:] [:lower:] | tr '0123456789abc' 'gtaio luSnemf'
