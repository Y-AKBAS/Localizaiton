#include <iostream>
#include <boost/locale.hpp>
#include <locale>
#include <string>
#include "collate_example.h"

int main()
{
    std::wcout << "user preferred locale is " << std::locale("").name().c_str() << std::endl;

    boost::locale::generator gen;
    gen.categories(boost::locale::collation_facet | boost::locale::formatting_facet);

    std::locale loc = gen("fr_FR.UTF-8");
    std::wcout.imbue(loc);

    setlocale(LC_ALL, "fr_FR.UTF-8");
    std::wstring lw = L"façade";
    std::wstring up = L"FaçaDe";

    bool isIdentical{};
    isIdentical = 0 == std::use_facet<boost::locale::collator<wchar_t>>(loc).compare(boost::locale::collator_base::secondary, lw, up);
    std::cout << std::boolalpha;
    std::cout << "eq: " << isIdentical << std::endl;

    std::wcout << lw << L" and " << up << L" are " << (isIdentical ? L"identical" : L"different") << std::endl;

    std::cout << "\n ===== Collate Example From Boost =========\n"
              << std::endl;

    collate_example_boost_ms();
    
    //  collate_example_boost_vec();
    //  collate_example_boost_list();

    return 0;
}