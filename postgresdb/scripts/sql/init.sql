CREATE TABLE exchanges (
    exchange_code VARCHAR(10) PRIMARY KEY,
    exchange_name VARCHAR(255) NOT NULL,
    city VARCHAR(50) NOT NULL,
    country VARCHAR(50) NOT NULL
);

INSERT INTO exchanges
VALUES
    ('NASDAQ', 'National Association of Securities Dealers Automated Quotations', 'New York City', 'United States of America'),
    ('NYSE', 'New York Stock Exchange', 'New York City', 'United States of America');

CREATE TABLE exchange_values (
    exchange_value_id SERIAL PRIMARY KEY,
    exchange_code VARCHAR(10) REFERENCES exchanges (exchange_code) NOT NULL,
    value INTEGER NOT NULL,
    timestamp TIMESTAMPTZ NOT NULL,
    -- Ensure a value is unique to a specific exchange and timestamp
    CONSTRAINT unique_exchange_ts
        UNIQUE (exchange_code, timestamp)
);

CREATE TABLE securities (
    security_id SERIAL PRIMARY KEY,
    symbol VARCHAR(10) NOT NULL,
    company_name VARCHAR(255) NOT NULL,
    exchange_code VARCHAR(10) REFERENCES exchanges (exchange_code) NOT NULL,
    -- Ensure a security is unique by its symbol and exchange
    CONSTRAINT unique_symbol_exchange
        UNIQUE (symbol, exchange_code)
);

CREATE TABLE security_prices (
    security_price_id BIGSERIAL PRIMARY KEY,
    security_id INTEGER REFERENCES securities (security_id) NOT NULL,
    price DECIMAL(12, 2) NOT NULL,
    timestamp TIMESTAMPTZ NOT NULL,
    -- Ensure a price is unique to a specific security and timestamp
    CONSTRAINT unique_security_ts
        UNIQUE (security_id, timestamp)
);