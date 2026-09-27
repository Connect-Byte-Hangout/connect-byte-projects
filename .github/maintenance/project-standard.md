# Padrão de projetos

Cada projeto publicado fica em `projects/<slug>/`, usando nomes em minúsculas,
sem acentos e separados por hífen.

## Estrutura

```text
projects/<slug>/
├── README.md          # documentação principal em português
├── README.en.md       # tradução em inglês
├── project.yml        # metadados usados pelo catálogo e pela validação
├── docs/              # materiais, montagem e conteúdo complementar
├── hardware/          # diagramas e arquivos de circuito
├── firmware/          # código embarcado (somente quando aplicável)
└── assets/            # fotos, PDFs e demais recursos
```

As quatro últimas pastas são opcionais. Quando `has_firmware` for `false`, a
pasta `firmware/` não deve existir. Quando for `true`, ela deve conter ao menos
um projeto PlatformIO com `platformio.ini` e `src/main.cpp`. Consulte o
[guia de instalação e uso do PlatformIO](../../docs/platformio.md).

## Metadados

O arquivo `project.yml` usa apenas campos simples para continuar legível e não
exigir bibliotecas adicionais:

```yaml
name: Nome público do projeto
slug: nome-do-projeto
status: published
date: TODO
has_firmware: false
cover: TODO
```

Valores desconhecidos devem permanecer como `TODO`. `cover`, quando definido,
é um caminho relativo à pasta do projeto.

## Novo projeto

O passo a passo completo está no
[manual interno para adicionar projetos](how-to-add-project.md).

Para criar um projeto sem firmware:

```sh
.github/maintenance/scripts/new-project nome-do-projeto "Nome do projeto"
```

Para criar um projeto com PlatformIO já preparado:

```sh
.github/maintenance/scripts/new-project nome-do-projeto "Nome do projeto" --firmware
```

Depois de preencher o projeto, um único comando valida os arquivos e atualiza o
catálogo e o site:

```sh
.github/maintenance/scripts/prepare-projects
```

Projetos novos começam com `status: draft`. Eles ganham uma página para revisão
local, mas só aparecem no catálogo público depois que o status for alterado para
`published`. O catálogo entre os marcadores no `README.md` da raiz é gerado; não
o edite manualmente.
