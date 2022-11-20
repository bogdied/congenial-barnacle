#include <iostream>
#include <vector>

void sort(std::vector<int>& vec);
void get_size_and_elements(std::vector<int>& vec);
void print_size_and_elements(std::vector<int>& vec);
void set_difference(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output);
void set_intersection(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output);
void set_union(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output);
void set_symmetrical_difference(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output);


int main() {

    std::vector<int> first;
    std::vector<int> second;

    get_size_and_elements(first);
    get_size_and_elements(second);

    sort(first);
    sort(second);

    std::vector<int> f_s_difference;
    set_difference(first, second, f_s_difference);
    print_size_and_elements(f_s_difference);

    std::vector<int> f_s_difference_stl;
    std::set_difference(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(f_s_difference_stl));
    print_size_and_elements(f_s_difference);

    std::vector<int> s_f_difference;
    set_difference(second, first, s_f_difference);
    print_size_and_elements(s_f_difference);

    std::vector<int> s_f_difference_stl;
    std::set_difference(second.begin(), second.end(), first.begin(), first.end(), std::back_inserter(s_f_difference_stl));
    print_size_and_elements(s_f_difference_stl);


    std::vector<int> intersection;
    set_intersection(first, second, intersection);
    print_size_and_elements(intersection);

    std::vector<int> Union;
    set_union(first, second, Union);
    print_size_and_elements(Union);

    std::vector<int> stl_union;
    std::set_union(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(stl_union));
    print_size_and_elements(Union);

    std::vector<int> symmetrical_difference;
    set_symmetrical_difference(first, second, symmetrical_difference);
    print_size_and_elements(symmetrical_difference);


}

void set_symmetrical_difference(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output){
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()){
        if (first[i] > second[j])
            ++j;
        else if (second[j] > first[i])
            ++i;
        else {
            first.erase(first.begin()+i);
            second.erase(second.begin()+j);
        }
    }
//    set_union(first,second,output);
    set_union(first, second,output);

}


void set_union(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output){
    set_difference(second, first, output);
    for (int & i : first){
        output.push_back(i);
    }
    sort(output);
}

void set_intersection(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output){
    int i = 0, j = 0;
    while (i < first.size() && j < second.size()){
        if (first[i] > second[j])
            ++j;
        else if (second[j] > first[i])
            ++i;
        else {
            output.push_back(first[i]);
            ++i;
            ++j;
        }
    }
}

void set_difference(std::vector<int>& first, std::vector<int>& second, std::vector<int>& output){
    int i = 0, j = 0;
    output = first;
    while (i < output.size() && j < second.size()){
        if (output[i] > second[j])
            ++j;
        else if (second[j] > output[i])
            ++i;
        else {
            output.erase(output.begin()+i);
        }
    }
}

void get_size_and_elements(std::vector<int>& vec){
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i){
        int temp;
        std::cin >> temp;
        vec.push_back(temp);
    }
}

void print_size_and_elements(std::vector<int>& vec){
    std::cout << vec.size() << '\n';
    for (int i : vec){
        std::cout << i << ' ';
    }
    std::cout << "\n\n";
}

void sort(std::vector<int>& vec) {
    for (int s = static_cast<int>(vec.size()) / 2; s > 0; s /= 2) {
        for (int i = s; i < vec.size(); ++i) {
            for (int j = i - s; j >= 0 && vec[j] > vec[j + s]; j -= s) {
                int temp = vec[j];
                vec[j] = vec[j + s];
                vec[j + s] = temp;
            }
        }
    }
}
