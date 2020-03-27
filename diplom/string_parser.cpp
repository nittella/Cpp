
#include "string_parser.h"

istringstream GetSubString(string_view& source){
    string sub_str;
    int i = 0;
    for (; i < source.size(); i++){
        if(source[i] != ' '){
            sub_str.push_back(source[i]);
        } else if(!sub_str.empty()){
            break;
        }
    }
    source.remove_prefix(i);
    istringstream stream(sub_str);
    return stream;
}
