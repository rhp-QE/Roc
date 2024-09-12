#ifdef __linux__
int ggcd(int a, int b) {
    return a + b;
}
#endif


#ifdef _WIN32
int ggcd(int a, int b) {
    return a - b;
}
#endif