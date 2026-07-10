🇺🇸 English | 🇧🇷 [Português](README.pt.md)

<p align="center">
  <img src="./assets/girlsJun.JPG" width="100%">
</p>

# Byte do Milhão 💜🎮

Real-time game show by the Connect Byte community — June Meetup (FIAP + MagaluCloud).

Using ESP32 as physical controllers, Node.js backend with WebSocket, and a gamified Next.js frontend.

🔗 [Project on Wokwi](https://wokwi.com/projects/465858648642294785)

---

## 🎮 Project Overview

**Byte do Milhão** is an interactive live game show for Connect Byte community events. Participants use physical ESP32 controllers to answer questions in real time, with a live-updated leaderboard and instant on-screen feedback.

<p align="center">
  <img src="./assets/projectJun.JPG" width="100%">
</p>

---

## 🗂️ Structure

- `backend`: Express + Socket.IO + TypeScript, with state persisted in PostgreSQL.
- `frontend`: Next.js + React + TypeScript + Tailwind CSS.
- `esp32-controller`: PlatformIO/Arduino firmware for ESP32 with physical buttons.
- `docs`: ESP32 integration examples.

---

## 🎯 Game Flow

1. Open the Arena.
2. Register a question.
3. Click **Start**.
4. Send answers via ESP32.
5. Click **Close**.
6. Click **Reveal**.
7. View the ranking and report.

---

## 🔌 Main Endpoints

| Method | Route | Description |
|--------|-------|-------------|
| `GET` | `/health` | Healthcheck |
| `GET` | `/state` | Current game state |
| `POST` | `/devices/register` | Register a device |
| `POST` | `/devices/heartbeat` | Device heartbeat |
| `POST` | `/questions` | Register a question |
| `POST` | `/answers` | Submit an answer |
| `POST` | `/game/start` | Start the game |
| `POST` | `/game/next-question` | Next question |
| `POST` | `/game/close-question` | Close the question |
| `POST` | `/game/reveal-question` | Reveal the answer |
| `POST` | `/game/reset` | Reset the game |
| `GET` | `/report` | Final report |

---

## 📦 Payload Examples

**Register a question:**
```json
{
  "text": "Which protocol is widely used in IoT?",
  "options": {
    "A": "SMTP",
    "B": "MQTT",
    "C": "FTP",
    "D": "LDAP"
  },
  "correctAnswer": "B",
  "durationSeconds": 30
}
```

**ESP32 — answer:**
```json
{
  "deviceId": "esp32-07",
  "answer": "B"
}
```

**ESP32 — heartbeat:**
```json
{
  "deviceId": "esp32-07"
}
```

---

## 📡 Socket.IO

**Events emitted by the server:**

- `device:online` / `device:offline`
- `answer:received`
- `question:started` / `question:closed` / `question:revealed`
- `ranking:updated`
- `narrator:message`
- `metrics:updated`
- `report:generated`

**Events sent by the client:**

- `dashboard:join`
- `host:start-question`
- `host:close-question`
- `host:reveal-question`

---

## 🏆 Scoring

| Condition | Points |
|-----------|--------|
| Correct answer | +100 |
| Within 2s | +50 |
| Within 5s | +30 |
| Within 10s | +10 |
| Streak ≥ 3 | +25 |
| Round MVP bonus | +25 |
| Wrong answer | 0 |

---

## 🔧 Testing with a Physical ESP32

The controller project is in `esp32-controller`. See the step-by-step guide at [`docs/esp32-platformio.md`](docs/esp32-platformio.md).

To work in VS Code, open the workspace:

```text
byte-do-milhao.code-workspace
```

Example with `curl`:

```bash
curl -X POST http://localhost:4000/answers \
  -H "Content-Type: application/json" \
  -d '{"deviceId":"esp32-07","answer":"B"}'
```

---

## Connect Byte
Website: https://connect-byte.org  
LinkedIn: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
