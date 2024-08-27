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

const A1 = [1, 3, 5, 7, 9];
const x1 = 3;
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

const A2 = [1, 3, 5, 7, 9];
const x2 = A2[0];]
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

// Teste para x = A[n]
const A3 = [1, 3, 5, 7, 9];
const x3 = A3[A3.length - 1];
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

const A4 = [1, 3, 5, 7, 9];
const x4 = -5;
```
