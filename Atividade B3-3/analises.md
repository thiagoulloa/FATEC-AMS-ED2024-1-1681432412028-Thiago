## Análises de Complexidade

**1. Busca Linear**

* **Pior Caso:** A chave está no último elemento ou não está presente no array.
* **Tempo de Execução:** O loop `for` itera `n` vezes no pior caso.
* **Função Algébrica:** `T(n) = n`
* **Notação Big O:** `O(n)` - Complexidade linear

**2. Busca Linear em Ordem (Array Ordenado)**

* **Pior Caso:** A chave é maior que todos os elementos do array ou não está presente.
* **Tempo de Execução:** O loop `for` itera no máximo `n` vezes.
* **Função Algébrica:** `T(n) = n`
* **Notação Big O:** `O(n)` - Embora possa terminar antes em alguns casos, o pior caso ainda é linear.

**3. Busca Binária (Array Ordenado)**

* **Pior Caso:** A chave não está presente no array, e o intervalo de busca é dividido ao meio repetidamente até que reste apenas um elemento.
* **Tempo de Execução:** O loop `while` reduz o intervalo de busca pela metade a cada iteração.  No pior caso, o número de iterações é `log₂(n)`.
* **Função Algébrica:** `T(n) = log₂(n)`
* **Notação Big O:** `O(log n)` - Complexidade logarítmica
