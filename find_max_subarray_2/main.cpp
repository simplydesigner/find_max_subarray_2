#include <iostream>
#include <vector>
#include <algorithm>

struct result {
    unsigned int begin_index;
    unsigned int end_index;
    int summary;
};

auto print_result(const result & result)
{
    std::cout << "[" << result.begin_index << ", " << result.end_index << "]: " << result.summary << std::endl;
}

auto find_max_subarray(const std::vector<int> & array) -> result
{
    unsigned int begin_index = 0;
    unsigned int end_index = 1;
    
    int max_summary = array[ 0 ];
    int summary = array[ 0 ];
    unsigned int candidate_index = 0;
    
    for ( unsigned int index = 1; index < array.size(); ++index ) {
        if ( summary < 0 ) {
            candidate_index = index;
            summary = 0;
        }
        
        summary += array[index];
        if ( max_summary < summary ) {
            max_summary = summary;
            begin_index = candidate_index;
            end_index = index;
        }
    }
    
    return {begin_index, end_index, max_summary};
}

auto print_array(const std::vector<int> & array)
{
    std::ostream_iterator<int> output_iterator(std::cout, " ");
    std::copy(array.begin(), array.end(), output_iterator);
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> array = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    
    print_array(array);
    
    auto result = find_max_subarray(array);
    print_result(result);
    
    return 0;
}
