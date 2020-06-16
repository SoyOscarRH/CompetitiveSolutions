impl Solution {
  pub fn valid_ip_address(ip : String) -> String {
    if validate_ip4 (&ip) { return String::from("IPv4"); }
    if validate_ip6 (&ip) { return String::from("IPv6"); }
    
    String::from("Neither")
  }
}

fn validate_ip4(data: &str) -> bool {
  let max_val = 1 << 8;
  let parts: Vec<&str> = data.split('.').collect();
  if parts.len() != 4 { return false; }

  parts.into_iter().all(|part| {
    if part.len() > 1 && part.starts_with('0') { return false; }
    let num = part.parse::<u32>().unwrap_or(max_val);
    0 <= num && num < max_val
  })
}

fn validate_ip6(data: &str) -> bool {
  let max_val = 1 << 16;
  let parts: Vec<&str> = data.split(':').collect();
  if parts.len() != 8 { return false; }

  parts.into_iter().all(|part| {
    if part .is_empty() || part.len() > 4 { return false; }
    let num = u32::from_str_radix(part, 16).unwrap_or(max_val);
    0 <= num && num < max_val
  })
}