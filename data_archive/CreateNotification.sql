CREATE TABLE "notification" (
    "id" text PRIMARY KEY,
    "staff_id" text NOT NULL,
    "leave_request_id" text,
    "title" text NOT NULL,
    "message" text NOT NULL,
    "created_at" timestamp NOT NULL,
    "is_read" boolean NOT NULL
);

ALTER TABLE "notification" ADD FOREIGN KEY ("staff_id") REFERENCES "staff_member" ("id") DEFERRABLE INITIALLY IMMEDIATE;

ALTER TABLE "notification" ADD FOREIGN KEY ("leave_request_id") REFERENCES "leave_request" ("id") DEFERRABLE INITIALLY IMMEDIATE;
