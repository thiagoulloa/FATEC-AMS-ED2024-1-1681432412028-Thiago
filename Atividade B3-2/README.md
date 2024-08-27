# Atividade da Disciplina de Estrutura de Dados - Fatec São Caetano do Sul 
### Trio: Kawai, Pedro e Thiago Ulloa - Apresentação:
![Resolução](linear_em_ordem_X∉A.png)



### Caso 1: x ∈ A

``` 
function buscaLinearEmOrdemCaso1(A, n, x) {
    let i = 0;
    while (i < n && x > A[i]) {
        if (A[i] === x) {
            return i;
        }
        i++;
    }
    return -1;
}

```


### Caso 2: x = A[1]

``` 
function buscaLinearEmOrdemCaso2(A, n, x) {
    let i = 0;
    while (i < n && x > A[i]) {
        if (A[i] === x) {
            return i;
        }
        i++;
    }
    return -1;
}

```


### Caso 3: x = A[n]

```
function buscaLinearEmOrdemCaso3(A, n, x) {
    let i = 0;
    while (i < n && x > A[i]) {
        if (A[i] === x) {
            return i;
        }
        i++;
    }
    return -1;
}

```


### Caso 4: x ∉ A

```
function buscaLinearEmOrdemCaso4(A, n, x) {
    let i = 0;
    while (i < n && x > A[i]) {
        if (A[i] === x) {
            return i;
        }
        i++;
    }
    return -1;
}

```
