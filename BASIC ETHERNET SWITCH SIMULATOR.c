#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_MAC_ENTRIES 20
#define MAX_PORTS 4

typedef struct {
    char mac[18];
    int port;
    time_t last_updated;
} MACTableEntry;

MACTableEntry mac_table[MAX_MAC_ENTRIES];
int mac_count = 0;

int find_mac_index(const char* mac) {
    for(int i=0; i<mac_count; i++) {
        if(strcmp(mac_table[i].mac, mac) == 0) return i;
    }
    return -1;
}

void learn_mac(const char* mac, int port) {
    int idx = find_mac_index(mac);
    if(idx >= 0) {
        mac_table[idx].port = port;
        mac_table[idx].last_updated = time(NULL);
        printf("Updated MAC %s at Port %d\n", mac, port);
    } else if(mac_count < MAX_MAC_ENTRIES){
        strcpy(mac_table[mac_count].mac, mac);
        mac_table[mac_count].port = port;
        mac_table[mac_count].last_updated = time(NULL);
        mac_count++;
        printf("Learned new MAC %s at Port %d\n", mac, port);
    } else {
        printf("MAC table full, cannot learn new MAC\n");
    }
}

void send_frame(const char* src_mac, const char* dst_mac, int src_port) {
    learn_mac(src_mac, src_port);
    int dst_index = find_mac_index(dst_mac);
    if(strcmp(dst_mac, "FF:FF:FF:FF:FF:FF") == 0 || dst_index == -1) {
        printf("Broadcast frame from Port %d to all ports except source\n", src_port);
        for(int p=1; p<=MAX_PORTS; p++) {
            if(p != src_port) printf("Forwarding to Port %d\n", p);
        }
    } else {
        int dst_port = mac_table[dst_index].port;
        if(dst_port == src_port) {
            printf("Destination on same port %d, frame dropped\n", src_port);
        } else {
            printf("Forwarding frame from Port %d to Port %d\n", src_port, dst_port);
        }
    }
}

void print_mac_table() {
    printf("\nMAC Address Table:\n");
    printf("MAC\t\t\tPort\n");
    printf("-------------------------------------\n");
    for(int i=0; i<mac_count; i++) {
        printf("%s\t%d\n", mac_table[i].mac, mac_table[i].port);
    }
    printf("-----------------------------\n");
}

int main() {
    char src[18], dst[18];
    int port;
    char cmd;

    printf("Ethernet Switch Simulator\n");
    
    while(1) {
        printf("\nCommands: s=send frame, m=show MAC table, q=quit\nEnter command: ");
        scanf(" %c", &cmd);

        if(cmd == 'q') break;
        else if(cmd == 'm') print_mac_table();
        else if(cmd == 's') {
            printf("Enter source MAC (XX:XX:XX:XX:XX:XX): ");
            scanf("%17s", src);
            printf("Enter destination MAC (XX:XX:XX:XX:XX:XX or FF:FF:FF:FF:FF:FF for broadcast): ");
            scanf("%17s", dst);
            printf("Enter source port (1-%d): ", MAX_PORTS);
            scanf("%d", &port);
            send_frame(src, dst, port);
        } else {
            printf("Unknown command\n");
        }
    }
    printf("Exiting...\n");
    return 0;
}
