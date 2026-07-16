CREATE TABLE "staff_member" (
  "id" text PRIMARY KEY,
  "first_name" text NOT NULL,
  "surname" text NOT NULL,
  "house_name_number" text,
  "street" text,
  "town" text,
  "postcode" text,
  "role" text NOT NULL,
  "employment_status" text NOT NULL,
  "manager_id" text
);

CREATE TABLE "leave_request" (
  "id" text PRIMARY KEY,
  "staff_id" text NOT NULL,
  "start_date" date NOT NULL,
  "end_date" date NOT NULL,
  "leave_reason" text NOT NULL,
  "leave_status" text NOT NULL
);

CREATE TABLE "leave_allowance" (
  "id" text PRIMARY KEY,
  "staff_id" text NOT NULL,
  "annual_entitlement" int NOT NULL,
  "remaining_leave" int NOT NULL
);

ALTER TABLE "leave_request" ADD FOREIGN KEY ("staff_id") REFERENCES "staff_member" ("id") DEFERRABLE INITIALLY IMMEDIATE;

ALTER TABLE "leave_allowance" ADD FOREIGN KEY ("staff_id") REFERENCES "staff_member" ("id") DEFERRABLE INITIALLY IMMEDIATE;

ALTER TABLE "staff_member" ADD FOREIGN KEY ("manager_id") REFERENCES "staff_member" ("id") DEFERRABLE INITIALLY IMMEDIATE;
