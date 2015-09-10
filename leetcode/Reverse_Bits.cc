const unordered_map<uint32_t, uint32_t> bits = {
  {1, 2147483648}, {2, 1073741824}, {4, 536870912}, {8, 268435456}, {16, 134217728}, 
  {32, 67108864}, {64, 33554432}, {128, 16777216}, {256, 8388608}, {512, 4194304}, 
  {1024, 2097152}, {2048, 1048576}, {4096, 524288}, {8192, 262144}, {16384, 131072}, 
  {32768, 65536}, {65536, 32768}, {131072, 16384}, {262144, 8192}, {524288, 4096}, 
  {1048576, 2048}, {2097152, 1024}, {4194304, 512}, {8388608, 256}, {16777216, 128}, 
  {33554432, 64}, {67108864, 32}, {134217728, 16}, {268435456, 8}, {536870912, 4}, 
  {1073741824, 2}, {2147483648, 1}
};
        
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret(0);
    for (auto &&pair : bits)
      if (n & pair.first)
	ret ^= pair.second;
    return ret;
  }
};