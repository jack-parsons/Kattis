    //https://open.kattis.com/problems/supercomputer

    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include <bitset>
    #include <math.h>
    #include <vector>
    #include <limits>
    using namespace std;

    #define BLOCKSIZE 256

    double logN(double n, double x) {
        // log n(x)
        return log(x) / log(n);
    }   

    struct Memory {
        private:
            vector<vector<int>> rangeCount;
            int layers, size;
            int counterHelper(int start, int end, int layer) {
                int count = 0;
                if (layer == 0) {
                    // Reached the final layer (actual counts)
                    for (int i = start; i < end; i++) {
                        count += rangeCount[0][i];
                    }
                    return count;
                }
                int blockSize = pow(BLOCKSIZE, layer);
                // If the range is within than a blocksize
                if ((end-start) <= blockSize) {
                    count += counterHelper(start, end, layer-1);
                } else {
                    // Count the start to the end of its block
                    count += counterHelper(start, (start/blockSize+1)*blockSize, layer-1);
                    // Count the end from the start of its block
                    count += counterHelper((end/blockSize)*blockSize, end, layer-1);

                    // Count the middle blocks
                    for (int i = start/blockSize+1; i < end/blockSize; i++) {
                        count += rangeCount[layer][i];
                    }
                }
                return count;
            }

        public:
            void initMemory(int s) {
                size = s;
                int s1 = pow(BLOCKSIZE, 1+(int)logN(BLOCKSIZE, size));
                for (int i = 0; i < ceil(logN(BLOCKSIZE, s1)); i++) {
                    rangeCount.push_back(vector<int>(s1/pow(BLOCKSIZE, i), 0));
                }
                layers = rangeCount.size();
            }

            void flip(int i) {
                int change = rangeCount[0][i]>0 ? -1 : 1;
                for (int l = 0; l < layers; l++) {
                    rangeCount[l][i/pow(BLOCKSIZE, l)] += change;
                }
            }
            
            int countRange(int start, int end) {
                return counterHelper(start, end+1, layers-1);//start on last layer
            }

            void print() {
                cout << endl;
                for (auto layer : rangeCount) {
                    for (auto x : layer) {
                        cout << x << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
    };

    int main(){
        int N, K;
        cin >> N >> K;

        Memory mem;
        mem.initMemory(N);

        for(int i = 0; i < K; i++){
            char val;
            cin >> val;
            switch (val){
                case 'C':
                    int start, end;
                    cin >> start >> end;
                    cout << mem.countRange(start, end)<<endl;
                    break;
                case 'F':
                    int index;
                    cin >> index;
                    mem.flip(index);
                break;
            }
        }

        return 0;
    }