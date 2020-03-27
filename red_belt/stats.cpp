#include "stats.h"

 // GET / HTTP/1.1
 // POST /order HTTP/1.1
HttpRequest ParseRequest(string_view line){
    size_t method_size = 0;
    string_view method;
    size_t start;
    start = line.find_first_not_of(' ');
    line.remove_prefix(start);
    method_size = line.find(' ');
    method = string_view(line.begin(), method_size);
    line.remove_prefix(method_size + 1);
    size_t uri_size = line.find(' ');
    string_view uri(line.begin(), uri_size);
    line.remove_prefix(uri_size + 1);
    return HttpRequest{method, uri, line};
};
Stats::Stats() {
        methods_stats = {
                {string_view(&methods[0][0], methods[0].size()), 0},
                {string_view(&methods[1][0], methods[1].size()), 0},
                {string_view(&methods[2][0], methods[2].size()), 0},
                {string_view(&methods[3][0], methods[3].size()), 0},
                {string_view(&methods[4][0], methods[4].size()), 0}
        };
        uris_stats = {
                {string_view(&uris[0][0], uris[0].size()), 0},
                {string_view(&uris[1][0], uris[1].size()), 0},
                {string_view(&uris[2][0], uris[2].size()), 0},
                {string_view(&uris[3][0], uris[3].size()), 0},
                {string_view(&uris[4][0], uris[4].size()), 0},
                {string_view(&uris[5][0], uris[5].size()), 0}
        };
}

void Stats::AddMethod(string_view method){
    if(methods_stats.find(method) != methods_stats.end()){
        ++methods_stats[method];
    } else {
        ++methods_stats["UNKNOWN"];
    }
};
void Stats::AddUri(string_view uri){
    if(uris_stats.find(uri) != uris_stats.end()){
        ++uris_stats[uri];
    } else {
        ++uris_stats["unknown"];
    }
};
const map<string_view, int>& Stats::GetMethodStats() const{
    return methods_stats;
};
const map<string_view, int>& Stats::GetUriStats() const{
    return uris_stats;
};
