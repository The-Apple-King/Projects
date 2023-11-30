made a check so that num_pixels doesn't overflow in parse bc_raw

FRMT can cause the program to stop as it xmallocs every time and theres no limit on FRMT tags

for bcprog we changed the do while loops to while loops, this will make sure we don't read to a wrong location early


bcraw line 200
    we check before every read are we about to read more than allocated for pixels

read_prog_data 336
    we check at every read that we won't read beyond expected
    check again at expanding data

read flat data 1627
    check for read beyond expected

for format string we check for less than 4 specifiers and not a single specifier that uses n