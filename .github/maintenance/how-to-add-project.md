# Como adicionar ou atualizar um projeto

Este manual é para as colaboradoras que organizam o repositório. Ele fica em
`.github/maintenance/` para não competir com os guias públicos das oficinas.

## Atualizar um projeto que já existe

Para alterar textos, imagens, materiais ou outras informações de um projeto já
publicado:

1. Abra o terminal na pasta principal deste repositório.
2. Inicie a prévia automática:

   ```sh
   .github/maintenance/scripts/preview-site
   ```

3. Abra `http://127.0.0.1:4173/` no navegador.
4. Deixe o comando rodando e faça as alterações dentro da pasta do projeto.
5. Salve o arquivo e espere a mensagem `Prévia atualizada` no terminal.
6. Recarregue a página no navegador para conferir o resultado.
7. Repita enquanto precisar. Para encerrar a prévia, pressione `Ctrl+C`.

O comando regenera o site e valida os projetos automaticamente sempre que
detecta uma alteração. Se a porta 4173 já estiver sendo usada por uma prévia
antiga, encerre o comando antigo com `Ctrl+C` antes de iniciar novamente.

Antes de enviar as mudanças ao GitHub, confirme que não há nenhuma linha marcada
como `ERRO`. Linhas marcadas como `AVISO` indicam informações conhecidamente
pendentes, como datas antigas que continuam como `TODO`.

## Adicionar um novo projeto

### 1. Escolha o nome

Separe duas informações:

- **Nome público em português:** como o projeto aparecerá no site, por exemplo
  `Planner financeiro físico`.
- **Slug em inglês:** nome curto da pasta, sem espaços, acentos ou letras
  maiúsculas, por exemplo `physical-financial-planner`.

### 2. Crie toda a estrutura

Abra o terminal na pasta principal deste repositório.

Se o projeto **não tem firmware**, execute:

```sh
.github/maintenance/scripts/new-project project-slug "Nome público do projeto"
```

Se o projeto **tem firmware**, execute:

```sh
.github/maintenance/scripts/new-project project-slug "Nome público do projeto" --firmware
```

Troque `project-slug` e `Nome público do projeto` pelos nomes escolhidos. A opção
`--firmware` já cria um projeto PlatformIO e define `has_firmware: true`. Sem
essa opção, o projeto é criado com `has_firmware: false`.

O novo projeto começa como `draft` (rascunho), portanto ainda não aparece no
catálogo público.

### 3. Coloque cada arquivo no lugar certo

Dentro de `projects/project-slug/`:

- `README.md`: explicação principal em português;
- `README.en.md`: versão em inglês; se ainda não houver tradução, mantenha o
  `TODO` em vez de inventar conteúdo;
- `docs/`: lista de materiais, montagem e outros textos;
- `assets/`: fotos, imagens e PDFs;
- `hardware/`: diagramas e arquivos do circuito;
- `firmware/`: código PlatformIO, somente quando o projeto usa firmware;
- `project.yml`: informações usadas pela automação e pelo site.

Use nomes de arquivos em minúsculas, sem acentos e separados por hífen, como
`foto-do-projeto.jpg`.

### 4. Preencha o `project.yml`

Exemplo:

```yaml
name: Nome público do projeto
slug: project-slug
status: draft
date: 2026-09-27
has_firmware: true
cover: assets/foto-do-projeto.jpg
```

- Use a data no formato `AAAA-MM-DD`.
- `cover` é o caminho da imagem de capa dentro do projeto.
- Não altere `has_firmware` se ele já foi definido pelo comando de criação.
- Se uma informação ainda for desconhecida, deixe `TODO`.

### 5. Cuide do firmware e dos dados sensíveis

Para projetos com firmware, ajuste `firmware/platformio.ini` para a placa usada
e coloque o programa em `firmware/src/main.cpp`.

Nunca publique senhas de Wi-Fi, tokens, chaves de API ou dados pessoais. Use um
arquivo de exemplo, como `config.example.h`, e mantenha o arquivo real ignorado
pelo Git. Se houver dúvida, peça uma revisão antes de publicar.

### 6. Atualize e confira tudo

Execute:

```sh
.github/maintenance/scripts/prepare-projects
```

Esse comando atualiza o catálogo e as páginas do site e, em seguida, valida os
metadados, nomes de arquivos, links, imagens e estrutura do firmware. Corrija
qualquer linha marcada como `ERRO`. Um `AVISO` de `TODO` pode permanecer enquanto
o projeto ainda for rascunho.

Para abrir uma prévia local, execute:

```sh
.github/maintenance/scripts/preview-site
```

Abra o endereço mostrado no terminal e deixe o comando rodando. Quando algum
texto, imagem, metadado ou arquivo do site for alterado, a prévia será gerada
novamente de forma automática. Basta recarregar a página no navegador. Para ver
um rascunho que ainda não está no catálogo, acesse diretamente
`/projects/project-slug/`. Pressione `Ctrl+C` para encerrar a prévia.

### 7. Publique o projeto

Quando textos, arquivos, links e capa estiverem conferidos, altere no
`project.yml`:

```yaml
status: published
```

Execute novamente `.github/maintenance/scripts/prepare-projects`, confira a
prévia e envie as alterações para revisão no GitHub. A verificação automática do
GitHub repetirá a validação e confirmará que o catálogo gerado está atualizado.

Não edite manualmente a tabela de projetos no `README.md` da raiz nem os arquivos
gerados dentro de `site/projects/`.
