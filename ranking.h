#include <map>
#include <vector>
#include <algorithm>

// Ordena ranking já retirando valores nulos de similaridade
std::vector <std::string> order_ranking(std::map <std::string, float> cosine);