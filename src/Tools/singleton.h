#ifndef SINGLETON_H
#define SINGLETON_H

#include <memory>
#include <mutex>

/**
 * @brief The Singleton class Classe utilitaire de gestion d'un singleton.
 */
template <typename T>
class Singleton
{
private:
    static std::once_flag m_onceFlag;   ///< Flag d'appel unique.

protected:
    /**
     * @brief Constructeur.
     */
    Singleton() = default;

    /**
     * @brief Destructeur.
     */
    virtual ~Singleton() = default;

    // Copie interdite
    Singleton(const Singleton& other) = delete;
    Singleton& operator=(const Singleton& other) = delete;

    /**
     * @brief The Deleter struct Is in charge to delete the element stored in the singleton.
     */
    struct Deleter
    {
        /**
         * @brief Delete the passed item.
         * @param item Item to delete.
         */
        void operator()(T* item) const
        {
            delete item;
        }
    };

protected:
    static std::unique_ptr<T, Deleter > m_instance; ///< Instance unique du singleton.

public:
    /**
     * @brief Récupère l'instance du singleton.
     * @return Unique instance.
     */
    static T& instance();
};

// Initialisation
template <typename T>
std::unique_ptr<T, typename Singleton<T>::Deleter> Singleton<T>::m_instance = nullptr;
template <typename T>
std::once_flag Singleton<T>::m_onceFlag;

template <typename T>
T& Singleton<T>::instance()
{
    std::call_once(m_onceFlag,
                   []
    {
        m_instance.reset(new T);
    });

    return *m_instance.get();
}

#endif // SINGLETON_H
