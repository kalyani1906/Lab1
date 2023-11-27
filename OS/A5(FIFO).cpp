#include <stdio.h>

int main() {
    int referenceString[10], pageFaults = 0, n, s, pages, frames;

    printf("\nEnter the number of Pages:\t");
    scanf("%d", &pages);

    printf("\nEnter reference string values:\n");
    for (n = 0; n < pages; n++) {
        printf("Value No. [%d]:\t", n + 1);
        scanf("%d", &referenceString[n]);
    }

    printf("\nWhat is the total number of frames:\t");
    scanf("%d", &frames);

    int temp[frames];
    for (n = 0; n < frames; n++) {
        temp[n] = -1;
    }

    for (n = 0; n < pages; n++) {
        s = 0;
        for (int i = 0; i < frames; i++) {
            if (referenceString[n] == temp[i]) {
                s++;
                pageFaults--;
            }
        }

        pageFaults++;

        if ((pageFaults <= frames) && (s == 0)) {
            temp[n] = referenceString[n];
        } else if (s == 0) {
            temp[(pageFaults - 1) % frames] = referenceString[n];
        }

        printf("\n");
        for (int i = 0; i < frames; i++) {
            printf("%d\t", temp[i]);
        }
    }

    printf("\nTotal Page Faults:\t%d\n", pageFaults);

    return 0;
}
