const state = { projects: [], filter: "all", search: "" };
const english = document.documentElement.lang === "en";

const grid = document.querySelector("#project-grid");
const emptyState = document.querySelector("#empty-state");
const template = document.querySelector("#project-card-template");
const search = document.querySelector("#project-search");
const filters = [...document.querySelectorAll(".filter")];

const normalized = (value) => value.normalize("NFD").replace(/[\u0300-\u036f]/g, "").toLowerCase();

function renderProjects() {
  const query = normalized(state.search.trim());
  const visible = state.projects.filter((project) => {
    const matchesSearch = normalized(`${project.name} ${project.summary}`).includes(query);
    const matchesFilter = state.filter === "all"
      || (state.filter === "firmware" && project.has_firmware)
      || (state.filter === "no-firmware" && !project.has_firmware);
    return matchesSearch && matchesFilter;
  });

  grid.replaceChildren();
  emptyState.hidden = visible.length > 0;

  visible.forEach((project) => {
    const card = template.content.cloneNode(true);
    const image = card.querySelector(".card-image");
    image.src = project.cover;
    image.alt = `Foto do projeto ${project.name}`;
    card.querySelector(".card-badge").textContent = project.has_firmware
      ? (english ? "Firmware available" : "Firmware disponível")
      : (english ? "No firmware available" : "Sem firmware disponível");
    card.querySelector("h3").textContent = project.name;
    card.querySelector(".card-summary").textContent = project.summary;
    const link = card.querySelector(".card-link");
    link.href = project.url;
    link.setAttribute("aria-label", `${english ? "View project" : "Ver projeto"} ${project.name}`);
    grid.append(card);
  });
}

search.addEventListener("input", (event) => {
  state.search = event.target.value;
  renderProjects();
});

filters.forEach((button) => {
  button.addEventListener("click", () => {
    state.filter = button.dataset.filter;
    filters.forEach((item) => {
      const active = item === button;
      item.classList.toggle("active", active);
      item.setAttribute("aria-pressed", String(active));
    });
    renderProjects();
  });
});

fetch(document.body.dataset.projects || "projects.json")
  .then((response) => {
    if (!response.ok) throw new Error("Projects could not be loaded.");
    return response.json();
  })
  .then((projects) => {
    state.projects = projects;
    document.querySelector("#project-count").textContent = projects.length;
    document.querySelector("#firmware-count").textContent = projects.filter((project) => project.has_firmware).length;
    renderProjects();
  })
  .catch(() => {
    grid.innerHTML = `<p class="loading">${english ? "Projects could not be loaded right now." : "Não foi possível carregar os projetos agora."}</p>`;
  });
