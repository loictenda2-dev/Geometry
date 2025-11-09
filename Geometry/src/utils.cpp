#ifndef UTILS_H
#define UTILS_H

// Inclusions standard nécessaires
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <iterator> // Pour std::next utilisé dans la map ToString

// --- Templates ToString ---

/**
 * 1. ToString de base (pour types fondamentaux)
 * Convertit toute valeur simple (int, float, string, etc.) en std::string.
 */
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

/**
 * 2. Surcharge de ToString pour std::vector
 * Convertit un vecteur en chaîne de caractères, format: [elem1, elem2, ...].
 */
template<typename T>
std::string ToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        // Utilise la version appropriée de ToString pour les éléments internes
        oss << ToString(v[i]); 
        if (i + 1 < v.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

/**
 * 3. Surcharge de ToString pour std::map
 * Convertit une map en chaîne de caractères, format: {key1: value1, key2: value2, ...}.
 */
template<typename K, typename V>
std::string ToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    // Utilisation d'un itérateur pour vérifier la fin et éviter la virgule finale
    for (auto it = m.begin(); it != m.end(); ++it) {
        // Utilise la version appropriée de ToString pour les clés et les valeurs
        oss << ToString(it->first) << ": " << ToString(it->second);
        if (std::next(it) != m.end()) oss << ", ";
    }
    oss << "}";
    return oss.str();
}

// --- Template Print (Utilise Fold Expression C++17) ---

/**
 * Fonction Print variadique
 * Prend un nombre variable d'arguments et les affiche sur une seule ligne 
 * en utilisant la fonction ToString appropriée pour chacun.
 */
template<typename T, typename... Args>
void Print(const T& first, const Args&... args) {
    // Affiche le premier argument (sans virgule avant)
    std::cout << ToString(first);
    
    // Utilise une "fold expression" (C++17) pour traiter le reste des arguments
    // et insérer ", " entre eux.
    ((std::cout << ", " << ToString(args)), ...);
    
    // Termine la ligne
    std::cout << std::endl;
}

#endif