#ifndef TEST_UTILS_H
#define TEST_UTILS_H

typedef int (*validate_func)(char *);

/*
* Fonction générique de test.
* @param line      : chaîne de test.
* @param expected  : valeur attendue.
* @param func      : fonction de validation à tester.
* @param type      : chaîne décrivant le type ("ambient", "light", "camera").
*/
void run_test(const char *line, int expected, validate_func func, const char *type);

#endif