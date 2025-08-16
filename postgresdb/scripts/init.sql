CREATE TABLE securities (
   isin VARCHAR(12) PRIMARY KEY,
   symbol VARCHAR(25) UNIQUE NOT NULL,
   company_name VARCHAR(255) UNIQUE NOT NULL,
   securities_exchange_id 
);

CREATE TABLE security_prices (
    security_price_id PRIMARY KEY,
    symbol VARCHAR(50) UNIQUE NOT NULL,
    isin
    FOREIGN KEY (isin) REFERENCES users (user_id)
);

CREATE TABLE securities_exchange_map(
    security_exchange_id SERIAL PRIMARY KEY,
    isin
    symbol VARCHAR(50) UNIQUE NOT NULL,
    company_name VARCHAR(255) UNIQUE NOT NULL
);