#include<array>
#include<iostream>
#include<string_view>
#include<tuple>
#include<type_traits>

namespace a::b::c
{
	inline constexpr std::string_view str{ "Hello" };
}
template<class...T>
std::tuple < std::size_t, std::common_type_t < T...>>sum(T...args)
{
	return{ sizeof...(T), (args + ...) };
}
int main()
{
	auto [iNumbers, iSum] {sum(1, 2, 3)};
	std::cout << a::b::c::str << ' ' << iSum << '\n';

	std::array arr{ 1,2,3 };
	std::cout << std::size(arr) << '\n';


/* y, x;
	y = 5;
	x = 6;
	std::cout << y + x; */



	return 0;

}