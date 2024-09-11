#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include "memchr_simd.h"

const char *data = " Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer aliquam sit amet lacus at faucibus. Duis venenatis nibh augue, ut semper nisl luctus sed. Nulla facilisi. Etiam ut ultrices tortor, facilisis porta est. Nam laoreet sodales nunc, et gravida felis rhoncus eu. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur iaculis turpis ac sapien sodales imperdiet. Maecenas lacus lacus, cursus et tortor nec, efficitur tristique nisl. Vivamus tempor, ligula molestie scelerisque porttitor, quam ligula tristique nisl, vel porttitor metus dolor non turpis. Quisque sit amet dolor a ante tincidunt cursus. Pellentesque libero lorem, varius id ornare sit amet, tempor eu metus. Pellentesque et odio tincidunt, molestie enim eget, sodales enim. Etiam porttitor commodo lectus, non tincidunt diam fringilla non. Fusce eu arcu eget erat lacinia vestibulum. Suspendisse id mauris ac ligula posuere pellentesque sit amet quis tellus. Sed ante diam, pulvinar ut neque sed, accumsan vehicula ligula. Praesent luctus, ex in volutpat tincidunt, magna risus feugiat sapien, ac auctor nisi lectus non ligula. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam quis orci nisl. Vestibulum ut gravida ex. Pellentesque sagittis massa elit, nec vehicula nisl luctus vel. In mollis, ante eget tempor gravida, est ante aliquet urna, a venenatis erat lorem in dolor. Vestibulum posuere eu ante id sodales. Sed vestibulum suscipit ante vitae rutrum. Integer sed accumsan nunc. Nullam magna dui, volutpat id tempus quis, placerat quis nisi. Sed vitae volutpat justo. Maecenas consequat nibh eget massa varius, ut convallis turpis malesuada. Vivamus sed sem id orci fringilla congue. In eget metus tempor, fermentum urna ac, convallis felis. Aenean consequat feugiat nisi cursus faucibus. Etiam ac orci neque. Aenean ac malesuada mi, quis tristique sem. Nam nulla lacus, dapibus a tempor mattis, pellentesque id purus. Nullam dui turpis, aliquam quis sem at, tincidunt rutrum lorem. Nulla lacinia nisi et turpis fermentum, sit amet facilisis nibh tempus. Sed finibus sem egestas felis placerat, vel euismod orci aliquam. Quisque id purus id diam consequat eleifend. Phasellus purus leo, tincidunt quis mi a, aliquam suscipit ligula. Nunc eu ex ultrices, blandit mauris ac, ornare nunc. Pellentesque faucibus ante nisl, sit amet bibendum justo ullamcorper nec. Duis vehicula, enim vitae maximus semper, ex odio placerat nulla, vel euismod risus arcu vel purus. Proin eget lorem sit amet ex blandit condimentum ac ac magna. Sed ultricies suscipit dui quis condimentum. Ut at pharetra velit. Nullam a velit faucibus, imperdiet turpis nec, volutpat sapien. Integer porta, ipsum sed dignissim fringilla, massa augue suscipit mauris, vitae consequat sem nunc sit amet nunc. Morbi pulvinar mauris at mauris sollicitudin, lobortis egestas est gravida. Mauris fermentum aliquet dui et faucibus. Duis sit amet elit est. Praesent eu orci eu eros finibus bibendum.";

int32_t main()
{
    int64_t pos_simd = memchr_simd('S', (int8_t *)data, strlen(data));

    printf("%ld, %c\n", pos_simd, data[pos_simd]);

    char * seq = "amet";
    uint64_t seq_len = strlen(seq);
    int64_t pos_seq_simd = memchr_sequance_simd((int8_t *)seq, (int8_t *) data, seq_len, strlen(data));

    printf("%ld ", pos_seq_simd);
    for (size_t i = 0; i < seq_len; i++)
        printf("%c", *(data+pos_seq_simd+i));

    printf("\n");
    
}