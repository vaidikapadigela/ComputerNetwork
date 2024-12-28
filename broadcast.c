#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to convert an IP address string to a 32-bit integer
uint32_t ipToInt(const char *ip) {
    uint32_t a, b, c, d;
    sscanf(ip, "%u.%u.%u.%u", &a, &b, &c, &d);
    return (a << 24) | (b << 16) | (c << 8) | d;
}

// Function to convert a 32-bit integer to an IP address string
void intToIp(uint32_t ip, char *buffer) {
    sprintf(buffer, "%u.%u.%u.%u", 
            (ip >> 24) & 0xFF, 
            (ip >> 16) & 0xFF, 
            (ip >> 8) & 0xFF, 
            ip & 0xFF);
}

// Function to calculate the subnet mask from a prefix length
uint32_t calculateSubnetMask(int prefixLength) {
    return prefixLength == 0 ? 0 : ~((1U << (32 - prefixLength)) - 1);
}

// Function to display subnet details
void displaySubnetInfo(int subnetNumber, uint32_t network, uint32_t broadcast, uint32_t subnetMask) {
    char buffer[16];
    printf("\nSubnet %d:\n", subnetNumber);
    printf("Network Address: ");
    intToIp(network, buffer);
    printf("%s\n", buffer);

    printf("Broadcast Address: ");
    intToIp(broadcast, buffer);
    printf("%s\n", buffer);

    printf("Subnet Mask: ");
    intToIp(subnetMask, buffer);
    printf("%s\n", buffer);

    printf("First Host: ");
    intToIp(network + 1, buffer);
    printf("%s\n", buffer);

    printf("Last Host: ");
    intToIp(broadcast - 1, buffer);
    printf("%s\n", buffer);
}

int main() {
    char ip[16];
    int prefixLength, newPrefixLength;
    uint32_t originalSubnetMask, newSubnetMask, ipInt;

    // Input IP address and prefix length
    printf("Enter IP address (e.g., 192.168.1.0): ");
    scanf("%15s", ip); // Limit input size to prevent overflow
    printf("Enter current prefix length (e.g., 24): ");
    scanf("%d", &prefixLength);

    // Calculate new prefix length for splitting the subnet
    newPrefixLength = prefixLength + 1;

    // Convert IP address to integer format
    ipInt = ipToInt(ip);

    // Calculate the original and new subnet masks
    originalSubnetMask = calculateSubnetMask(prefixLength);
    newSubnetMask = calculateSubnetMask(newPrefixLength);

    // Calculate the number of hosts per subnet
    int hostsPerSubnet = (1 << (32 - newPrefixLength)) - 2; // Subtract 2 for network and broadcast addresses

    // Output summary
    printf("\nNumber of subnets: 2\n");
    printf("Number of hosts per subnet: %d\n", hostsPerSubnet);

    // Generate and display details for each subnet
    for (int i = 0; i < 2; i++) {
        uint32_t subnetNetwork = (ipInt & originalSubnetMask) | (i << (32 - newPrefixLength));
        uint32_t subnetBroadcast = subnetNetwork | ~newSubnetMask;

        displaySubnetInfo(i + 1, subnetNetwork, subnetBroadcast, newSubnetMask);
    }

    return 0;
}
