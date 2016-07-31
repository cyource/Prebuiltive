#define __STDC_FORMAT_MACROS
#include <stdio.h>
#include <stdint.h>
#include<iostream>
//#include <algorithm>
//#include<vector>
#include<stdlib.h>
#include<cpu-features.h>
#include<sys/system_properties.h>
#include<string>
#include <inttypes.h>

using namespace std;

class Properties {
    public:
        Properties();
        string android_returnCpuFamily();
};

Properties::Properties() {
    string strt = "</> Prebuiltive: A Cyourceware";
    string dashes;
    for (char c: strt) {
        dashes += "-";
    }
    cout << dashes <<endl
         << strt << endl
         << dashes << endl;
}

string Properties::android_returnCpuFamily(){
    string android_givenCpuFamilies[] = { "ARM", "X86", "MIPS", "ARM64", "X86_64", "MIPS64" };
    AndroidCpuFamily android_getCpuFamily();
    for (int i = 0; i < 6; i++) {
        if (android_getCpuFamily() == i) {
            return android_givenCpuFamilies[i];
        }
    }
    return "[ERROR: Failed to identify CPU Family]";
}

int main() {
    Properties props;
    if (getenv("ANDROID_PROPERTY_WORKSPACE")) {
    bool quit = false;
    while (!quit) {
        string input;
        cout << ">> ";
        getline(cin, input);
        if (input == "cpu family") {
            cout << props.android_returnCpuFamily() << endl;
        } else if (input == "cpu count") {
            int android_getCpuCount(void);
            cout << android_getCpuCount << endl;
        } else if (input == "cpu feataflag") {
            uint64_t android_getCpuFeatures();
            printf("%" PRIu64 "\n", android_getCpuFeatures());
        } else if (input == "sdk -v") {
            FILE* sdk = popen("getprop ro.build.version.sdk", "a");
            cout << pclose(sdk) << endl;
        } else if (input == "os -v") {
            FILE* release = popen("getprop ro.build.version.release", "a");
            cout << pclose(release) << endl;
        } else if (input == "device model") {
            FILE* model = popen("getprop ro.product.model", "a");
            cout << pclose (model) << endl;
        } else if (input == "quit") {
            quit = true;
        } else {
            cout << "[ERROR: Command not recognised]" << endl;
        }
    }
    } else {
        cout << "[ERROR: Android workspace required]" << endl;
    }
    return 0;
}

