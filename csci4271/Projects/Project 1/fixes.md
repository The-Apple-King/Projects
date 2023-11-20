made a check so that num_pixels doesn't overflow in parse bc_raw

FRMT can cause a crash to the program as it xmallocs every time and theres no limit on FRMT tags

bcraw line 200
    we check before every read are we about to read more than allocated for pixels

read_prog_data 336
    we check at every read that we won't read beyond expected
    check again at expanding data

read flat data 1627
    check for read beyond expected


idea for checking, make sure that pixels pointer doesn't get bigger than location of info