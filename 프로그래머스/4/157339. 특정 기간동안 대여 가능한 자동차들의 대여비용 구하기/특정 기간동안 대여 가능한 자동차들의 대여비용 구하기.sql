select s.car_id, s.car_type, round((s.daily_fee*(100-c.discount_rate)/100*30)) as fee
from car_rental_company_discount_plan c
join (
    select car_id, car_type,daily_fee
    from car_rental_company_car 
    where car_type in ('세단','SUV') 
    and car_id not in (
        select distinct(car_id)
        from car_rental_company_rental_history
        where end_date >= to_date('20221101','yyyymmdd') 
            and start_date <= to_date('20221130','yyyymmdd')
    )
) s 
on c.duration_type='30일 이상' and c.car_type = s.car_type
where
    round(s.daily_fee*(100-c.discount_rate)/100*30)>=500000 
    and round(s.daily_fee*(100-c.discount_rate)/100*30)<2000000
order by fee desc, car_type asc, car_id desc