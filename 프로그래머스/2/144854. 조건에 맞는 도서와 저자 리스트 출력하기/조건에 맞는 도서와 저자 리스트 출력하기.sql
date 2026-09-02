-- 코드를 입력하세요
SELECT b.book_id, a.author_name, to_char(b.published_date,'yyyy-mm-dd')
from book b 
join author a on b.author_id = a.author_id
where b.category='경제'
order by b.published_date asc