SELECT CATEGORY, SUM(SALES) AS TOTAL_SALES
FROM BOOK, BOOK_SALES
WHERE BOOK.BOOK_ID = BOOK_SALES.BOOK_ID 
AND SALES_DATE BETWEEN DATE('2022-01-01') AND DATE('2022-01-31')
GROUP BY CATEGORY
ORDER BY CATEGORY