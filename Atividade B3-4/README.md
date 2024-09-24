# Projeto Simulação de Blockchain

## Capa

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

---

## Macro Solução

A solução foi implementada em Rust, utilizando estruturas básicas de dados para representar blocos e a cadeia de blocos. A mineração ocorre ao encontrar um valor de `nonce` que gera um hash válido de acordo com o nível de dificuldade definido.

### Estrutura do Projeto

- **Bloco**: Contém o índice, timestamp, dados, hash do bloco anterior, hash do bloco atual e o `nonce`.
- **Blockchain**: Um vetor de blocos que forma a cadeia.
- **Transação**: Contém o remetente, destinatário e valor da transação.

### Detalhes de Implementação

#### 1. Mineração de Bloco

Cada bloco é minerado ao tentar diferentes valores de `nonce` até encontrar um hash válido que atenda a dificuldade exigida (número de zeros iniciais no hash).

**Laço de repetição**: Um loop `while` é utilizado para incrementar o valor de `nonce` até encontrar o hash que satisfaça o nível de dificuldade.

```rust
while !self.prova_de_trabalho(dificuldade) {
    self.nonce += 1;
}
```

#### 2. Adição de transações

As transações são adicionadas a um vetor dentro do bloco.

**Laço de repetição**: Um loop for é utilizado para iterar sobre as transações e adicioná-las ao bloco.

```rust
for transacao in transacoes {
self.transacoes.push(transacao);
}
```

#### 3. Exibição da Blockchain

Os blocos são exibidos com todas as suas informações, como índice, timestamp, dados, hash anterior e o hash gerado.

**Laço de repetição**: Um loop for é utilizado para percorrer e exibir todos os blocos da blockchain.

```rust
for bloco in &self.cadeia {
println!("{:?}", bloco);
}
```

#### 4. Validação da Blockchain

A blockchain é validada verificando-se se o hash de cada bloco corresponde ao hash calculado e se o hash anterior de cada bloco corresponde ao hash do bloco anterior.

Recursividade: A função valida_blockchain_recursiva percorre a cadeia de blocos de forma recursiva, comparando o bloco atual com o anterior.

```rust
fn valida_blockchain_recursiva(&self, indice: usize) -> bool {
    if indice == 0 {
        return true;
    }

    let bloco_atual = &self.cadeia[indice];
    let bloco_anterior = &self.cadeia[indice - 1];

    if bloco_atual.hash != bloco_atual.calcula_hash() {
        return false;
    }

    if bloco_atual.hash_anterior != bloco_anterior.hash {
        return false;
    }

    self.valida_blockchain_recursiva(indice - 1)
}
```

#### 5. Busca de Transações por Remetente (Recursividade)

**Recursividade**: A função buscar_transacoes_por_remetente utiliza recursão para percorrer a blockchain e encontrar todas as transações realizadas por um remetente específico.

```rust
fn buscar_transacoes_por_remetente(&self, remetente: &str, indice: usize) -> Vec<Transacao> {
    if indice == 0 {
        return Vec::new();
    }

    let bloco_atual = &self.cadeia[indice];
    let mut transacoes_encontradas = bloco_atual.transacoes
        .iter()
        .filter(|t| t.remetente == remetente)
        .cloned()
        .collect::<Vec<Transacao>>();

    transacoes_encontradas.append(&mut self.buscar_transacoes_por_remetente(remetente, indice - 1));
    transacoes_encontradas
}
```

## Conclusão

Com essas estruturas principais, conseguimos implementar uma blockchain funcional que cumpre os requisitos de segurança, imutabilidade e descentralização. A blockchain valida os blocos automaticamente, garantindo a integridade de cada um. Adicionalmente, a função de busca recursiva permite encontrar transações específicas de forma eficiente.

## Ferramentas e Tecnologias Utilizadas

### Linguagem de Programação:

**Rust**: Escolhida pela sua segurança de memória, alta performance e o excelente suporte à concorrência, que são cruciais para a implementação de sistemas como blockchains.

### Bibliotecas Utilizadas:

**sha2**: Utilizada para gerar hashes com o algoritmo SHA-256. A função de hash é fundamental para a criação de blocos seguros e imutáveis na blockchain.

**Observação**: Este documento fornece uma estrutura básica para o projeto de simulação de blockchain. A implementação completa em Rust requer a definição das estruturas de dados Bloco e Transacao, além da lógica para a prova de trabalho e outras funcionalidades da blockchain.
