#include "point.h"
#include <sstream> // Pour utiliser std::ostringstream dans ToString
#include <cmath>   // Pour std::sin, std::cos, et M_PI (ou une alternative)

// Pour une meilleure portabilité du radian PI, nous allons le définir
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// --- Fonctions de Création ---

/**
 * Crée et retourne un nouveau Point2f.
 */
Point2f MakeP2f(float x, float y) {
    return {x, y};
}

// --- Fonctions de Translation ---

/**
 * Translate un point par des offsets dx et dy.
 */
Point2f Translate(const Point2f& p, float dx, float dy) {
    return {p.x + dx, p.y + dy};
}

/**
 * Translate un point en utilisant un vecteur de translation.
 * Nécessite que Vector2f ait les membres x et y.
 */
Point2f Translate(const Point2f& p, const Vector2f& v) {
    // Supposons que Vector2f a les membres 'x' et 'y'
    return {p.x + v.x, p.y + v.y};
}

// --- Fonctions de Mise à l'Échelle (Scaling) ---

/**
 * Met à l'échelle un point par des facteurs sx et sy (par rapport à l'origine (0,0)).
 */
Point2f Scale(const Point2f& p, float sx, float sy) {
    return {p.x * sx, p.y * sy};
}

/**
 * Met à l'échelle un point en utilisant un vecteur de facteurs d'échelle.
 * Nécessite que Vector2f ait les membres x et y.
 */
Point2f Scale(const Point2f& p, const Vector2f& s) {
    // Supposons que Vector2f a les membres 'x' et 'y'
    return {p.x * s.x, p.y * s.y};
}

// --- Fonction de Rotation ---

/**
 * Fait tourner un point autour de l'origine (0,0) par un angle donné en degrés.
 * La rotation est généralement effectuée dans le sens anti-horaire.
 */
Point2f Rotate(const Point2f& p, float angleDegree) {
    // Convertir les degrés en radians
    float angleRad = angleDegree * (M_PI / 180.0f);
    float cosA = std::cos(angleRad);
    float sinA = std::sin(angleRad);
    
    // Formule de rotation:
    // x' = x * cos(A) - y * sin(A)
    // y' = x * sin(A) + y * cos(A)
    
    float newX = p.x * cosA - p.y * sinA;
    float newY = p.x * sinA + p.y * cosA;
    
    return {newX, newY};
}

// --- Fonction Utilitaires ---

/**
 * Convertit le Point2f en une chaîne de caractères de format "(x, y)".
 */
std::string ToString(const Point2f& p) {
    std::ostringstream oss;
    // La fonction fixed et std::setprecision peuvent être utilisées pour contrôler la précision
    oss << "(" << p.x << ", " << p.y << ")";
    return oss.str();
}