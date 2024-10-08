## Projeto Simulação de Blockchain

**Identificação dos componentes da equipe:**

- Pedro Nascimento
- Matheus Macedo
- Kawai Soares
- Thiago Ulloa
- Guilherme Pradela

---

## Descrição de Negócio

O objetivo deste projeto é criar uma simulação de uma blockchain utilizando a linguagem Rust, com foco nos princípios fundamentais de uma blockchain, como segurança, imutabilidade e descentralização. Este projeto simula um processo de mineração, geração de hashes e validação de blocos. A blockchain resultante é uma cadeia de blocos que contém transações fictícias, sendo minerados por meio de um algoritmo de "prova de trabalho".

### Problema a ser resolvido

A blockchain busca resolver questões de segurança e confiança ao armazenar dados de forma descentralizada. Em um sistema tradicional, os dados podem ser manipulados ou perdidos, mas com uma blockchain:

- **Segurança**: Os dados são protegidos por criptografia.
- **Imutabilidade**: Após inseridos, os dados não podem ser modificados sem invalidar os blocos subsequentes.
- **Descentralização**: Os dados podem ser verificados sem depender de uma entidade central.

### Objetivo

O objetivo é criar um sistema de blockchain funcional que realiza as seguintes tarefas:

1. Mineração de blocos, onde um hash válido deve ser encontrado.
2. Validação da blockchain para garantir a integridade dos blocos.
3. Armazenamento de transações em blocos, com um processo de verificação baseado em "prova de trabalho".

## Macro Solução

Este documento descreve a implementação de uma blockchain simples em Rust, utilizando uma lista ligada como estrutura de dados para armazenar os blocos. A implementação inclui a criação de um bloco gênesis, a mineração de novos blocos e a validação da blockchain.

## Estruturas do Projeto

### 1. Estrutura do Bloco

```Rust
struct Block {
    index: u64,
    timestamp: u128,
    data: String,
    previous_hash: String,
    hash: String,
    nonce: u64,
    next: Option<Box<Block>>, // Apontador para o próximo bloco
}
```

- **`index: u64`**: O índice do bloco na cadeia.
- **`timestamp: u128`**: O timestamp em milissegundos representando quando o bloco foi minerado.
- **`data: String`**: Os dados contidos no bloco (por exemplo, transações).
- **`previous_hash: String`**: O hash do bloco anterior, garantindo a ligação entre os blocos.
- **`hash: String`**: O hash atual do bloco, que é calculado durante a mineração.
- **`nonce: u64`**: Um número usado para a mineração, que é incrementado até que um hash válido seja encontrado.
- **`next: Option<Box<Block>>`**: Um ponteiro para o próximo bloco na lista ligada.

### 2. Estrutura da Blockchain

A estrutura `Blockchain` representa a cadeia de blocos e contém os seguintes campos:

```rust
struct Blockchain {
    head: Option<Box<Block>>, // Primeira referência na lista ligada
    difficulty: usize,
}
```

- **`head: Option<Box<Block>>`**: A referência ao primeiro bloco (cabeça) da lista ligada.
- **`difficulty: usize`**: O nível de dificuldade para a mineração, que determina quantos zeros iniciais devem estar presentes no hash.

### Laços de Repetição

O sistema faz uso de laços de repetição tanto para encontrar o último bloco da blockchain quanto para realizar a mineração dos novos blocos.

1. **Mineração (Proof of Work)**:

   - Durante a mineração, a função `mine_block` ajusta o valor do `nonce` repetidamente até que o hash do bloco satisfaça o critério de dificuldade.
   - Este laço ocorre na linha:
     ```rust
     while !Blockchain::is_valid_hash(&new_block.hash, self.difficulty) {
         new_block.nonce += 1;
         new_block.hash = Blockchain::calculate_hash(&new_block);
     }
     ```

2. **Inserção de Bloco**:

   - A inserção de um novo bloco na blockchain também envolve um laço para encontrar o último bloco na lista ligada:
     ```rust
     let mut current = &mut self.head;
     while let Some(ref mut block) = current {
         if block.next.is_none() {
             // Insere o novo bloco
             ...
         }
         current = &mut block.next;
     }
     ```

3. **Validação da Blockchain com Recursividade**:

   - A validação recursiva da blockchain é feita para verificar a integridade da cadeia, garantindo que o hash de cada bloco corresponde ao valor esperado, baseado nos dados e hash anterior.

     ```rust
        // Valida a blockchain recursivamente
        fn validate_chain_recursively(&self) -> bool {
            if let Some(ref block) = self.head {
                return Blockchain::validate_block_recursively(block);
            }
            true
        }

        // Valida cada bloco com o anterior usando recursão
        fn validate_block_recursively(block: &Block) -> bool {
            if let Some(ref next_block) = block.next {
                if block.hash != next_block.previous_hash {
                    return false;
                }
                if next_block.hash != Blockchain::calculate_hash(next_block) {
                    return false;
                }
                return Blockchain::validate_block_recursively(next_block);
            }
            true
        }
     ```

4. **Validação da Blockchain com Iteração**:
   - A validação utiliza um laço while para iterar sobre todos os blocos da blockchain, comparando o hash atual de cada bloco com o hash referenciado no próximo bloco.
     ```rust
        // Valida a blockchain utilizando iteração
        fn validate_chain_iteratively(&self) -> bool {
            let mut current = &self.head;

            // Verifica a integridade de cada bloco em relação ao anterior
            while let Some(ref block) = current {
                if let Some(ref next_block) = block.next {
                    // Verifica se o hash atual do bloco é igual ao hash anterior do próximo bloco
                    if block.hash != next_block.previous_hash {
                        return false;
                    }
                    // Verifica se o hash do próximo bloco é válido
                    if next_block.hash != Blockchain::calculate_hash(next_block) {
                        return false;
                    }
                }
                current = &block.next;
            }
            true
        }
     ```

---

## Ferramentas e Linguagens Utilizadas

- **Rust**: Linguagem de programação utilizada para implementar a simulação da blockchain. Rust oferece segurança de memória e excelente desempenho para sistemas concorrentes, como blockchains.
- **Sha2**: Biblioteca utilizada para gerar hashes criptográficos no padrão **SHA-256**, que é amplamente utilizado em blockchains reais, como o Bitcoin.
- **Sistema de Tempo (SystemTime)**: Utilizado para gerar o timestamp de cada bloco, permitindo o registro de quando o bloco foi criado.
- **Cargo**: Ferramenta de build e gerenciamento de pacotes do ecossistema Rust.

---

## Análise Assintótica: Iteração vs. Recursividade na Validação da Blockchain

### Iteração

**Vantagem**:

- Direto e eficiente: O loop for percorre a cadeia de forma linear, realizando um número constante de operações por bloco.
- Menor sobrecarga: Não há chamadas de função recursivas, o que reduz a sobrecarga da pilha.

**Desvantagem**:

- Menos elegante: Para problemas recursivos, a solução iterativa pode ser menos intuitiva.

**Análise:**
A complexidade de tempo da iteração é O(n), onde n é o número de blocos na blockchain. Isso significa que o tempo de execução cresce linearmente com o tamanho da entrada.

### Recursividade

**Vantagem**:

- Elegante: A solução recursiva reflete a natureza hierárquica da blockchain.
- Mais concisa: A lógica pode ser mais concisa em alguns casos.

**Desvantagem**:

- Sobrecarga de chamadas: Cada chamada recursiva consome memória da pilha.
- Menos eficiente: A chamada de função recursiva tem um custo adicional.

**Análise:**
A complexidade de tempo da recursividade também é O(n), pois cada bloco é visitado apenas uma vez. No entanto, a constante implícita na notação O pode ser maior devido às chamadas de função recursivas.

---

Para analisar e determinar a performance de ambos os códigos (um usando recursividade e outro usando iteração) através da notação Big O, precisamos avaliar o comportamento dos algoritmos de validação de blockchain.

### 1. *Cenário Recursivo:*

No código recursivo, a validação da blockchain é feita através da função validate_block_recursively. A função é chamada recursivamente para cada bloco, verificando a integridade entre o bloco atual e o próximo. Cada chamada à função consome espaço adicional na pilha de chamadas do sistema.

- *Espaço*: A recursão usa espaço de pilha proporcional à profundidade da lista (número de blocos), ou seja, O(n) em espaço, onde n é o número de blocos na blockchain.
- *Tempo*: Cada bloco é visitado uma vez e cada comparação e cálculo de hash tem um custo constante, então o tempo é O(n), onde n é o número de blocos.

*Complexidade recursiva*:
- *Tempo*: O(n)
- *Espaço*: O(n) (devido ao uso de memória adicional para armazenar as chamadas recursivas na pilha).

### 2. *Cenário Iterativo:*

No código iterativo, a validação da blockchain é feita através da função validate_chain_iteratively. Aqui, o algoritmo percorre a lista de blocos usando um loop while. O espaço de memória consumido é constante, pois não há chamadas recursivas aninhadas, e o código visita cada bloco uma vez.

- *Espaço*: O algoritmo não usa memória extra além de variáveis locais e ponteiros para os blocos, então o espaço é O(1).
- *Tempo*: Assim como na versão recursiva, cada bloco é visitado uma vez e as operações de comparação e cálculo de hash têm custo constante, então o tempo também é O(n).

*Complexidade iterativa*:
- *Tempo*: O(n)
- *Espaço*: O(1) (constante, já que não depende do número de blocos).

### *Conclusão*:

- *Tempo*: Ambos os algoritmos têm a mesma complexidade de tempo, O(n), porque ambos percorrem a lista de blocos uma vez e fazem comparações constantes.
- *Espaço*: O algoritmo iterativo é mais eficiente em termos de espaço, com O(1), enquanto o recursivo consome O(n) devido à pilha de chamadas.

Portanto, a versão *iterativa* é mais *eficiente* em termos de *espaço* (memória), especialmente em blockchains grandes, onde o espaço de pilha poderia ser um gargalo no algoritmo recursivo.

| Função                  | Descrição                                                                                                      | Complexidade de Tempo | Complexidade de Espaço |
|-------------------------|----------------------------------------------------------------------------------------------------------------|-----------------------|------------------------|
| `mine_block`            | Minera um novo bloco encontrando o hash válido baseado na dificuldade. Calcula o hash repetidamente até que a condição seja atendida. | O(2^d), onde d é a dificuldade, pois é necessário tentar várias vezes até encontrar um hash válido. | O(1), pois usa apenas variáveis locais para manter o bloco atual. |
| `calculate_hash`        | Calcula o hash de um bloco baseado nos dados do bloco.                                                          | O(1), já que o tamanho do bloco e seus campos são fixos e pequenos. | O(1), pois o hash é calculado em tempo constante. |
| `is_valid_hash`         | Verifica se o hash do bloco começa com o número de zeros exigido pela dificuldade.                              | O(d), onde d é a dificuldade, já que compara os primeiros d caracteres do hash. | O(1), pois a verificação do hash requer espaço constante. |
| `create_genesis_block`  | Cria o bloco gênesis da blockchain.                                                                             | O(1), pois a criação do bloco envolve operações simples. | O(1), pois é necessário apenas espaço para o bloco gênesis. |
| `current_timestamp`     | Obtém o timestamp atual do sistema.                                                                             | O(1), pois apenas acessa o relógio do sistema. | O(1), pois o timestamp é armazenado em uma variável simples. |
| `display`               | Exibe todos os blocos da blockchain.                                                                            | O(n), onde n é o número de blocos, já que percorre a lista de blocos. | O(1), pois apenas utiliza variáveis locais para percorrer a lista. |

---

**Link para a apresentação:** [Canva](https://www.canva.com/design/DAGSQjGojX4/ea6rMgsWqI3yVJyqBWWXeg/edit?utm_content=DAGSQjGojX4&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton)
