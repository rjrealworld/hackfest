BEGIN {
    receive = 0
    drop = 0
}

{
    if ($1 == "r" && $4 == 4) {
        receive++
    }
    if ($1 == "d" && $4 == 4) {
        drop++
    }
} 

END {
    printf("\nTotal packets lost: %d", drop)
    printf("\nTotal packets received:: %d", receive)
}
