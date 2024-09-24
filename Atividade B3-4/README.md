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

A solução foi implementada em Rust, utilizando estruturas básicas de dados para representar blocos e a cadeia de blocos. A mineração ocorre ao encontrar um valor de `nonce` que gera um hash válido de acordo com o nível de dificuldade definido.

### Estrutura do Projeto

- **Bloco**: Contém o índice, timestamp, dados, hash do bloco anterior, hash do bloco atual e o `nonce`.
- **Blockchain**: Um vetor de blocos que forma a cadeia.

### Detalhes de Implementação

#### 1. Mineração de Bloco
Cada bloco é minerado ao tentar diferentes valores de `nonce` até encontrar um hash válido que atenda a dificuldade exigida (número de zeros iniciais no hash).

**Laço de repetição**: Um loop `while` é utilizado para incrementar o valor de `nonce` até encontrar o hash que satisfaça o nível de dificuldade.

```rust
while !self.prova_de_trabalho(dificuldade) {
    self.nonce += 1;
}
```

#### 2. Exibição da Blockchain
Os blocos são exibidos com todas as suas informações, como índice, timestamp, dados, hash anterior e o hash gerado.

**Laço de repetição**: Um loop for é utilizado para percorrer e exibir todos os blocos da blockchain.

```rust
for bloco in &self.cadeia {
    println!("{:?}", bloco);
}
```


#### 3. Validação da Blockchain

A blockchain é validada verificando-se se o hash de cada bloco corresponde ao hash calculado e se o hash anterior de cada bloco corresponde ao hash do bloco anterior.

**Iteração:** A função `valida_blockchain_iterativa` percorre a cadeia de blocos de forma iterativa, comparando cada bloco com o anterior.

```rust
fn valida_blockchain_iterativa(&self) -> bool {
    // Começamos do segundo bloco, pois o primeiro não tem bloco anterior para comparar
    for i in 1..self.cadeia.len() {
        let bloco_atual = &self.cadeia[i];
        let bloco_anterior = &self.cadeia[i - 1];

        if bloco_atual.hash != bloco_atual.calcula_hash() ||
           bloco_atual.hash_anterior != bloco_anterior.hash {
            return false;
        }
    }
    return true;
}
```

