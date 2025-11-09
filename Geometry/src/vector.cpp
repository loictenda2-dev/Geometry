#include "vector.h"
#include "point.h" // Nécessaire pour Point2f
#include <cmath>   // Pour std::sqrt
#include <sstream> // Pour ToString

// --- Fonctions de Création ---

/**
 * Crée un nouveau vecteur 2D à partir de ses composantes x et y.
 */
Vector2f MakeV2f(float x, float y) {
    return {x, y};
}

/**
 * Crée un vecteur allant du point 'a' au point 'b' (V = b - a).
 * Nécessite que Point2f ait les membres x et y.
 */
Vector2f MakeV2f(const Point2f& a, const Point2f& b) {
    return {b.x - a.x, b.y - a.y};
}

// --- Fonctions Algébriques de Base ---

/**
 * Additionne deux vecteurs (composante par composante).
 */
Vector2f Add(const Vector2f& a, const Vector2f& b) {
    return {a.x + b.x, a.y + b.y};
}

/**
 * Soustrait le vecteur b du vecteur a (a - b).
 */
Vector2f Sub(const Vector2f& a, const Vector2f& b) {
    return {a.x - b.x, a.y - b.y};
}

/**
 * Multiplie les composantes du vecteur par un scalaire.
 */
Vector2f Scale(const Vector2f& v, float scalar) {
    return {v.x * scalar, v.y * scalar};
}

// --- Fonctions Mathématiques Avancées ---

/**
 * Calcule le produit scalaire (Dot Product) de deux vecteurs.
 * Résultat : a.x * b.x + a.y * b.y
 */
float Dot(const Vector2f& a, const Vector2f& b) {
    return a.x * b.x + a.y * b.y;
}

/**
 * Calcule la magnitude (longueur ou norme) du vecteur.
 * Résultat : sqrt(x^2 + y^2)
 */
float Length(const Vector2f& v) {
    // Utiliser Dot pour calculer x^2 + y^2
    return std::sqrt(Dot(v, v));
}

/**
 * Calcule le vecteur unitaire (de longueur 1) dans la même direction que v.
 */
Vector2f Normalize(const Vector2f& v) {
    float len = Length(v);
    
    // Évite la division par zéro si le vecteur est nul
    if (len > 0.0f) {
        float invLen = 1.0f / len;
        return {v.x * invLen, v.y * invLen};
    }
    // Retourne le vecteur nul si la longueur est zéro
    return {0.0f, 0.0f};
}

/**
 * Calcule l'interpolation linéaire (Linear Interpolation) entre deux vecteurs.
 * Lerp(a, b, t) = a + (b - a) * t
 * Où t est un facteur entre 0 (retourne a) et 1 (retourne b).
 */
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t) {
    // Formule optimisée : a * (1 - t) + b * t
    float one_minus_t = 1.0f - t;
    return {
        a.x * one_minus_t + b.x * t,
        a.y * one_minus_t + b.y * t
    };
}

/**
 * Calcule le déterminant 2x2 (également appelé produit extérieur ou perp dot product).
 * Utilisé pour déterminer si 'b' est à gauche ou à droite de 'a', et pour le calcul de l'aire signée.
 * Résultat : a.x * b.y - a.y * b.x
 */
float Determinant(const Vector2f& a, const Vector2f& b) {
    return a.x * b.y - a.y * b.x;
}

// --- Fonction Utilitaire ---

/**
 * Convertit le Vector2f en une chaîne de caractères de format "<x, y>".
 */
std::string ToString(const Vector2f& v) {
    std::ostringstream oss;
    oss << "<" << v.x << ", " << v.y << ">";
    return oss.str();
}