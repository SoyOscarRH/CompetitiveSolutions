fn num_of_days_to_finish_book(pages_in_chapters: &Vec<i32>, max_pages_per_day: i32) -> i32 {
    pages_in_chapters.iter().fold(0, |days, pages| {
        days + (pages / max_pages_per_day) + (if pages % max_pages_per_day != 0 { 1 } else { 0 })
    })
}

fn min_num_pages_per_day_if_finish_in(pages_in_chapters: &Vec<i32>, days: i32) -> Option<i32> {
    let mut min_num_pages = 1;
    let mut max_num_pages = *(pages_in_chapters.iter().max()?);

    while min_num_pages < max_num_pages {
        let pages_per_day = min_num_pages + (max_num_pages - min_num_pages) / 2;
        let days_to_finish = num_of_days_to_finish_book(&pages_in_chapters, pages_per_day);

        if days_to_finish <= days {
            max_num_pages = pages_per_day
        } else {
            min_num_pages = pages_per_day + 1
        }
    }

    if min_num_pages == max_num_pages {
        Some(min_num_pages)
    } else {
        None
    }
}

fn main() {
    let days = min_num_pages_per_day_if_finish_in(&vec![5, 3, 4], 4);
    match days {
        Some(days) => println!("{}", days),
        None => println!("Not possible"),
    }
}
