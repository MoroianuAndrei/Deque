#include "Deque.h"

int main()
{
    int choice;
    Deque<int> dq;

    std::cout << "1. Adauga element la inceput" << std::endl;
    std::cout << "2. Adauga element la sfarsit" << std::endl;
    std::cout << "3. Sterge primul element" << std::endl;
    std::cout << "4. Sterge ultimul element" << std::endl;
    std::cout << "5. Afiseaza primul element" << std::endl;
    std::cout << "6. Afiseaza ultimul element" << std::endl;
    std::cout << "7. Afiseaza daca este vida" << std::endl;
    std::cout << "8. Goleste structura" << std::endl;
    std::cout << "9. Afiseaza numarul de elemente stocate in structura" << std::endl;
    std::cout << "10. Afiseaza elementul dorit []" << std::endl;
    std::cout << "11. Insereaza un element la pozitia dorita" << std::endl;
    std::cout << "12. Sterge un element de la pozitia dorita" << std::endl;
    std::cout << "13. Afisare" << std::endl;
    std::cout << "14. Iesire" << std::endl << std::endl;

    while (true)
    {
        std::cout << "Introduceti optiunea: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            int val1;
            std::cout << "Introduceti valoarea ce se doreste a fi adaugata la inceputu: ";
            std::cin >> val1;
            std::cout << std::endl;
            dq.push_front(val1);
            break;
        case 2:
            int val2;
            std::cout << "Introduceti valoarea ce se doreste a fi adaugata la sfarsit: ";
            std::cin >> val2;
            std::cout << std::endl;
            dq.push_back(val2);
            break;
        case 3:
            dq.pop_front();
            break;
        case 4:
            dq.pop_back();
            break;
        case 5:
            std::cout << "Primul element este: " << dq.front() << std::endl;
            break;
        case 6:
            std::cout << "Ultimul element este: " << dq.back() << std::endl;
            break;
        case 7:
            if (dq.empty())
                std::cout << "Este vida" << std::endl;
            else
                std::cout << "Nu este vida" << std::endl;
            break;
        case 8:
            dq.clear();
            break;
        case 9:
            std::cout << "Numarul de elemente stocate in structura este: " << dq.size() << std::endl;
            break;
        case 10:
            int it;
            std::cout << "Introduceti pozitia elementului cautat: ";
            std::cin >> it;
            std::cout << "Elementul de la pozitia " << it << " este: " << dq[it - 1] << std::endl;
            break;
        case 11:
            int element, poz;
            std::cout << "Introduceti elementul ce se doreste inserat: ";
            std::cin >> element;
            std::cout << "Introduceti pozitia la care se doreste inserarea elementului: ";
            std::cin >> poz;
            dq.insert(element, poz);
            break;
        case 12:
            int poz1;
            std::cout << "Introduceti pozitia de la care se doreste stergerea unui element: ";
            std::cin >> poz1;
            dq.del(poz1);
            break;
        case 13:
            dq.print();
            break;
        case 14:
            std::cout << "Ati iesit din program!" << std::endl;
            return 0;
        default:
            std::cout << "Optiune invalida. Alegeti din nou." << std::endl;
        }
    }
}