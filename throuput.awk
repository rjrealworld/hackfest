BEGIN {
    startTime = 0
    finishTime = 0
    flag = 0
    fileSize = 0
    throughput = 0
    latency = 0
}

{
    if ($1 == "r" && $4 == 4) {
        fileSize += $6
        if (flag == 0) {
            startTime = $2
            flag = 1
        }
        finishTime = $2
    }
}

END {
    latency = finishTime - startTime
    throughput = (fileSize * 8) / latency
    printf("\n Latency: %f", latency)
    printf("\n Throughput: %f", throughput)
}
