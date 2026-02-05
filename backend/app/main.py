from fastapi import FastAPI
from pydantic import BaseModel
from typing import List, Optional

app = FastAPI(title="XDR Backend")


class Event(BaseModel):
    type: str
    timestamp_ns: int
    host: str
    process: Optional[str] = None
    path: Optional[str] = None
    details: Optional[str] = None


_events: List[Event] = []


@app.get("/health")
def health():
    return {"status": "ok"}


@app.post("/ingest/events")
def ingest_events(events: List[Event]):
    _events.extend(events)
    return {"ingested": len(events)}


@app.get("/events")
def list_events(limit: int = 100):
    return {"events": _events[-limit:]}
