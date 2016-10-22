#ifndef STRINGALGORITHMS_H
#define STRINGALGORITHMS_H

#include <algorithm>
#include <map>
#include <sstream>
#include <vector>

template <typename T>
/**
 * @brief Verifie si la string termine par la string endStr.
 * @param str String à tester.
 * @param endStr String avec laquelle str doit se terminer.
 * @return True si la string termine par endStr, sinon false.
 */
bool endsWith(const std::basic_string<T>& str, const std::basic_string<T>& endStr);

template <typename T>
/**
 * @brief Verifie si la string commence par la string startStr.
 * @param str String à tester.
 * @param startStr String avec laquelle str doit commencer.
 * @return True si la string commence par startStr, sinon false.
 */
bool startsWith(const std::basic_string<T>& str, const std::basic_string<T>& startStr);

template <typename T>
/**
 * @brief toLower Convertit une string en minuscules.
 * @param str String à convertir.
 * @return String en minuscules.
 */
std::basic_string<T> toLower(const std::basic_string<T>& str);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <typename T>
bool endsWith(const std::basic_string<T>& str, const std::basic_string<T>& endStr)
{
    size_t strSize = str.size();
    size_t endStrSize = endStr.size();

    if (strSize < endStrSize)
        return false;

    typename std::basic_string<T>::const_reverse_iterator itStr = str.crbegin();
    typename std::basic_string<T>::const_reverse_iterator itEndStr = endStr.crbegin();
    while (itEndStr != endStr.crend())
    {
        if (*itStr != *itEndStr)
            return false;
        ++itStr;
        ++itEndStr;
    }

    return true;
}

template <typename T>
bool startsWith(const std::basic_string<T>& str, const std::basic_string<T>& startStr)
{
    size_t strSize = str.size();
    size_t startStrSize = startStr.size();

    if (strSize < startStrSize)
        return false;

    typename std::basic_string<T>::const_iterator itStr = str.cbegin();
    typename std::basic_string<T>::const_iterator itStartStr = startStr.cbegin();
    while (itStartStr != startStr.cend())
    {
        if (*itStr != *itStartStr)
            return false;
        ++itStr;
        ++itStartStr;
    }

    return true;
}

template <typename T>
std::basic_string<T> toLower(const std::basic_string<T>& str)
{
    typename std::basic_string<T> out(str);
    std::transform(str.begin(), str.end(), out.begin(), ::tolower);
    return out;
}



#endif // STRINGALGORITHMS_H
