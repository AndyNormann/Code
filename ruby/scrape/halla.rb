require 'httparty'
require 'nokogiri'
require 'json'
require 'pry'
require 'csv'

page = HTTParty.get('http://www.gulesider.no/finn:snekker%20oslo')

parse_page = Nokogiri::HTML(page)

#File.open("outfile.html", 'w') { |file| file.write(parse_page) }

links = parse_page.css("a[class='stripped-link lightblue-link profile-page-link addax addax-cs_hl_hit_company_name_click']")

links.each do |link|
    #puts link["href"]
    puts link.text

    cur_page = HTTParty.get('http://www.guleside.no' + link["href"])
    parse_cur_page = Nokogiri::HTML(cur_page)

    #info = parse_cur_page.css("div[class='address-and-opening-hours']")
    telephone = parse_cur_page.css("span[class='tel clearfix']")
    puts telephone[0].text

    address = parse_cur_page.css("span[class='street-address display-block']")
    puts address.text

    postal_code = parse_cur_page.css("span[class='postal-code']")
    puts postal_code[0].text

    comp_info = parse_cur_page.css("div[class='financial-information-wrap white-box']")
    org_nr = comp_info.css("dl[class='financial-information-facts']")
    lines = org_nr.text.split('\n')
    break
end


#Pry.start(binding)
