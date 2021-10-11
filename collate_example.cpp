#include "collate_example.h"

boost::locale::generator gen;
std::locale loc = gen.generate("fr_FR.UTF-8");
boost::locale::comparator<wchar_t> myComparator(loc, boost::locale::collator_base::secondary);

void display_ms(const std::multiset<std::wstring, boost::locale::comparator<wchar_t>> &ms)
{
    // std::wcout.imbue(loc);
    for (const auto &name : ms)
    {
        std::wcout << name << std::endl;
    }
}

void display_vec(const std::vector<std::wstring> &vec)
{
    //std::wcout.imbue(loc);
    for (const auto &name : vec)
    {
        std::wcout << name << std::endl;
    }
}

void display_list(const std::list<std::wstring> &l)
{
    //std::wcout.imbue(loc);
    for (const auto &name : l)
    {
        std::wcout << name << std::endl;
    }
}

void collate_example_boost_ms()
{
    Timer timer;
    timer.start();

    boost::locale::generator gen;
    std::locale loc = gen.generate("fr_FR.UTF-8");
    boost::locale::comparator<wchar_t> myComparator(loc, boost::locale::collator_base::secondary);
    std::wcout << L"Result" << myComparator.operator()(L"ali", L"bli") << std::endl;
    std::wcout << L"Result" << myComparator.operator()(L"bli", L"ali") << std::endl;

    typedef std::multiset<std::wstring, boost::locale::comparator<wchar_t>> multiset_type;
    multiset_type names_multiset(myComparator);

    // std::ios_base::sync_with_stdio(false);

    // std::wifstream in_file(L"Names.txt");

    // if (!in_file)
    // {
    //     std::cerr << "File not open" << std::endl;
    //     std::exit(1);
    // }
    // std::wstring name;

    // while (!in_file.eof())
    // {
    //     std::getline(in_file, name);
    //     names.insert(name);
    // }
    // in_file.close();

    names_multiset.insert(L"zébra");
    names_multiset.insert(L"Feliçita");
    names_multiset.insert(L"feliçita");
    names_multiset.insert(L"hôtel");
    names_multiset.insert(L"Hôtel");
    names_multiset.insert(L"FèliçiTa");
    names_multiset.insert(L"Fèliçita");
    names_multiset.insert(L"FèliçiTa");
    names_multiset.insert(L"faliçita");

    std::cout << "Size of the names multiset: " << names_multiset.size() << std::endl;
    std::cout << std::endl;

    display_ms(names_multiset);
    timer.stop();
    std::cout << "\nElapsed time at multiset: " << std::fixed << timer << std::endl;
}

void collate_example_boost_vec()
{
    Timer timer;
    timer.start();

    std::vector<std::wstring> names_vector;

    names_vector.push_back(L"zébra");
    names_vector.push_back(L"Feliçita");
    names_vector.push_back(L"feliçita");
    names_vector.push_back(L"hôtel");
    names_vector.push_back(L"Hôtel");
    names_vector.push_back(L"FèliçiTa");
    names_vector.push_back(L"Fèliçita");
    names_vector.push_back(L"FèliçiTa");
    names_vector.push_back(L"faliçita");

    sort(names_vector.begin(), names_vector.end());

    display_vec(names_vector);

    timer.stop();
    std::cout << "\nElapsed time at vector: " << std::fixed << timer << std::endl;
}

void collate_example_boost_list()
{
    Timer timer;
    timer.start();

    std::list<std::wstring> names_list;

    names_list.push_back(L"zébra");
    names_list.push_back(L"Feliçita");
    names_list.push_back(L"feliçita");
    names_list.push_back(L"hôtel");
    names_list.push_back(L"Hôtel");
    names_list.push_back(L"FèliçiTa");
    names_list.push_back(L"Fèliçita");
    names_list.push_back(L"FèliçiTa");
    names_list.push_back(L"faliçita");

    // sort(names_list.begin(), names_list.end(), [](std::wstring l, std::wstring r)
    //      { return myComparator(l, r); });

    display_list(names_list);

    timer.stop();
    std::cout << "\nElapsed time at list: " << std::fixed << timer << std::endl;
}