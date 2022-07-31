FT_END=$(expr $FT_LINE2 + 1)
cat /etc/passwd | sed -n 'n;s/:.*$//;p' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p;${FT_END}q" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./'
