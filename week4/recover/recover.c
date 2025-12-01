#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    FILE *inptr = fopen("card.raw", "rb");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open card.raw\n");
        return 1;
    }

    uint8_t buffer[512];
    FILE *outptr = NULL;
    int filecount = 0;
    char filename[8]; 
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inptr)) > 0)
    {
        bool is_jpeg = (bytesRead >= 4) &&
                       buffer[0] == 0xff &&
                       buffer[1] == 0xd8 &&
                       buffer[2] == 0xff &&
                       (buffer[3] & 0xf0) == 0xe0; // 0xe0..0xef

        if (is_jpeg)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            sprintf(filename, "%03d.jpg", filecount++);
            outptr = fopen(filename, "wb");
            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s\n", filename);
                fclose(inptr);
                return 2;
            }
        }

        if (outptr != NULL)
        {
            fwrite(buffer, 1, bytesRead, outptr);
        }
    }

    if (outptr != NULL)
        fclose(outptr);
    fclose(inptr);
    return 0;
}
