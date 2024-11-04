#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mysql.h"
#include <cstring>

#pragma comment(lib, "libmysql.lib")

const char* host = "localhost";
const char* user = "root";
const char* pw = "mysql";
const char* db = "project";

int main(void) {

    MYSQL* connection = NULL;
    MYSQL conn;
    MYSQL_RES* sql_result;
    MYSQL_ROW sql_row;

    if (mysql_init(&conn) == NULL)
        printf("mysql_init() error!");

    connection = mysql_real_connect(&conn, host, user, pw, db, 3306, (const char*)NULL, 0);
    if (connection == NULL)
    {
        printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
        return 1;
    }

    else
    {
        printf("Connection Succeed");

        if (mysql_select_db(&conn, db))
        {
            printf("%d ERROR : %s\n", mysql_errno(&conn), mysql_error(&conn));
            return 1;
        }

        FILE* fp;
        fp = fopen("20212022_1.txt", "r");
        while (!feof(fp))
        {
            char data[1024];
            if (!fgets(data, 1024, fp))
                break;
            mysql_query(connection, data);
        }
        fclose(fp);

        while (1) {
            printf("\n\n------- SELECT QUERY TYPES -------\n\n");
            printf("\t1. TYPE 1\n");
            printf("\t2. TYPE 2\n");
            printf("\t3. TYPE 3\n");
            printf("\t4. TYPE 4\n");
            printf("\t5. TYPE 5\n");
            printf("\t6. TYPE 6\n");
            printf("\t7. TYPE 7\n");
            printf("\t0. QUIT\n");
            printf("\n----------------------------------\n");

            int command = 0;
            printf(">    select a query type : ");
            scanf("%d", &command);

            if (command == 0) break;
            
            else if (command == 1) {
                printf("\n\n--- TYPE 1 ---\n\n");
                printf("**Find address of homes for sale in the district 'Mapo'.\n");
                
                char query1[1000] = { 0, };
                sprintf(query1, "select m.market_id, m.name\nfrom market as m\nwhere m.address = 'Mapo';");

                int state = 0;
                state = mysql_query(connection, query1);
                if (state == 0)
                {
                    int flag = 1;
                    sql_result = mysql_store_result(connection);
                    printf("\n%-30s %-30s\n", "Property ID", "Name");
                    while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                    {
                        flag = 0;
                        printf("%-30s %-30s\n", sql_row[0], sql_row[1]);
                        break;
                    }
                    if (flag) {
                        printf("There are no satisfactory properties.");
                    }
                    mysql_free_result(sql_result);
                    printf("\n");
                }
                
                while (1) {
                    printf("\n\n----- Subtypes in TYPE 1 -----\n");
                    printf("\t1. TYPE 1-1\n");
    
                    int subcmd = 0;
                    printf(">    select a subquery type : ");
                    scanf("%d", &subcmd);

                    if (subcmd == 0) break;
                    else if (subcmd == 1) {
                        printf("**find the costing between ₩ 1,000,000,000 and ₩1,500,000,000.\n");

                        char query1_1[1000] = { 0, };
                        sprintf(query1_1, "select m.market_id, m.name\nfrom market as m\nwhere m.address = 'Mapo' and m.price between 1000000000 and 1500000000");

                        int state = 0;
                        state = mysql_query(connection, query1_1);
                        if (state == 0)
                        {
                            int flag = 1;
                            sql_result = mysql_store_result(connection);
                            printf("\n%-30s %-30s\n", "Property ID", "Name");
                            while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                            {
                                flag = 0;
                                printf("%-30s %-30s\n", sql_row[0], sql_row[1]);
                                break;
                            }
                            if (flag) {
                                printf("There are no satisfactory properties.");
                            }
                            mysql_free_result(sql_result);
                            printf("\n");
                        }
                    }
                }
            }
            else if (command == 2) {
                printf("\n\n--- TYPE 2 ---\n\n");
                printf("**Find the address of homes for sale in the 8th school district.\n");
                
                char query2[1000] = { 0, };
                sprintf(query2, "select m.market_id, m.name\nfrom market as m\nwhere m.school_district = 8;");

                int state = 0;
                state = mysql_query(connection, query2);
                if (state == 0)
                {
                    int flag = 1;
                    sql_result = mysql_store_result(connection);
                    printf("\n%-30s %-30s\n", "Property ID", "Name");
                    while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                    {
                        flag = 0;
                        printf("%-30s %-30s\n", sql_row[0], sql_row[1]);
                        break;
                    }
                    if (flag) {
                        printf("There are no satisfactory properties.");
                    }
                    mysql_free_result(sql_result);
                    printf("\n");
                }
                
                while (1) {
                    printf("\n\n----- Subtypes in TYPE 2 -----\n");
                    printf("\t1. TYPE 2-1\n");
    
                    int subcmd = 0;
                    printf(">    select a subquery type : ");
                    scanf("%d", &subcmd);

                    if (subcmd == 0) break;
                    else if (subcmd == 1) {
                        printf("**find properties with 4 or more bedrooms and 2 bathrooms.\n");

                        char query2_1[1000] = { 0, };
                        sprintf(query2_1, "select m.market_id, m.name\nfrom market as m\njoin market_room as mr on m.market_id = mr.market_id\njoin room as r on mr.room_id = r.room_id\nwhere m.school_district = 8 and r.bed_room >= 4 and r.bath_room = 2;");
                        int state = 0;
                        state = mysql_query(connection, query2_1);
                        if (state == 0)
                        {
                            int flag = 1;
                            sql_result = mysql_store_result(connection);
                            printf("\n%-30s %-30s\n", "Property ID", "Name");
                            while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                            {
                                flag = 0;
                                printf("%-30s %-30s\n", sql_row[0], sql_row[1]);
                                break;
                            }
                            if (flag) {
                                printf("There are no satisfactory properties.");
                            }

                            mysql_free_result(sql_result);
                            printf("\n");
                        }
                    }
                }
            }
            else if (command == 3) {
                printf("\n\n--- TYPE 3 ---\n\n");
                printf("**Find the name of the agent who has sold the most properties in the year 2022 by total won value.\n");
                
                char query3[1000] = { 0, };
                sprintf(query3, "select a.agent_id, a.name\nfrom agent as a\njoin agent_sold as ags on a.agent_id = ags.agent_id\njoin sold as s on ags.sold_id = s.sold_id\nwhere s.sold_date = 2022\ngroup by a.name\norder by sum(s.price) desc limit 1;");
                int state = 0;
                state = mysql_query(connection, query3);
                if (state == 0)
                {
                    int flag = 1;
                    sql_result = mysql_store_result(connection);
                    printf("\n%-30s %-30s\n", "Agent ID", "Name");
                    while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                    {
                        flag = 0;
                        printf("%-30s %-30s\n", sql_row[0], sql_row[1]);
                        break;
                    }
                    if (flag) {
                        printf("There are no satisfied agents.");
                    }
                    mysql_free_result(sql_result);
                    printf("\n");
                }
                
                while (1) {
                    printf("\n\n----- Subtypes in TYPE 3 -----\n");
                    printf("\t1. TYPE 3-1\n");
                    printf("\t2. TYPE 3-2\n");
    
                    int subcmd = 0;
                    printf(">    select a subquery type : ");
                    scanf("%d", &subcmd);

                    if (subcmd == 0) break;
                    else if (subcmd == 1) {
                        printf("**Find the top k agents in the year 2023 by total won value.\n");
                        printf("**Insert Number : ");
                        int k = 0;
                        scanf("%d",&k);

                        char query3_1[1000] = { 0, };
                        sprintf(query3_1, "select a.agent_id, a.name\nfrom agent as a\njoin agent_sold as ags on a.agent_id = ags.agent_id\njoin sold as s on ags.sold_id = s.sold_id\nwhere s.sold_date = 2023\ngroup by a.name\norder by sum(s.price) desc limit %d;",k);

                        int state = 0;
                        state = mysql_query(connection, query3_1);
                        if (state == 0)
                        {
                            int flag = 1;
                            sql_result = mysql_store_result(connection);
                            printf("\n%-30s %-30s\n", "Agent ID", "Name");
                            while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                            {
                                flag = 0;
                                printf("%-30s %-30s\n", sql_row[0], sql_row[1]);
                                break;
                            }
                            if (flag) {
                                printf("There are no satisfied agents.");
                            }
                            mysql_free_result(sql_result);
                            printf("\n");
                        }
                    }
                    else if (subcmd == 2) {
                        printf("**Find the bottom 10% agents in the year 2021 by total won value.\n");

                        char query3_2[1000] = { 0, };
                        sprintf(query3_2, "with TotalValue as (select a.agent_id, a.name, sum(s.price) as total_value from agent as a join agent_sold as ags on a.agent_id = ags.agent_id\njoin sold as s on ags.sold_id = s.sold_id\nwhere s.sold_date = 2021\ngroup by a.agent_id, a.name),TotalAgents as (select count(*) as cnt\nfrom TotalValue), Bottom10Percent as (select total_value\nfrom TotalValue\norder by total_value\nlimit (select cnt / 10 from TotalAgents))\nselect a.agent_id, a.name\nfrom TotalValue as a\njoin Bottom10Percent as b on a.total_value = b.total_value\norder by a.total_value;");

                        int state = 0;
                        state = mysql_query(connection, query3_2);
                        if (state == 0)
                        {
                            int flag = 1;
                            sql_result = mysql_store_result(connection);
                            printf("\n%-30s %-30s\n", "Agent ID", "Name");
                            while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                            {
                                flag = 0;
                                printf("%-30s %-30s\n", sql_row[0], sql_row[1]);
                                break;
                            }
                            if (flag) {
                                printf("There are no satisfied agents.");
                            }
                            mysql_free_result(sql_result);
                            printf("\n");
                        }
                    }
                }
            }
            else if (command == 4) {
                printf("\n\n--- TYPE 4 ---\n\n");
                printf("**For each agent, compute the average selling price of properties sold in 2022, and the average time the property was on the market.\n");

                char query4[1000] = { 0, };
                sprintf(query4, "select a.agent_id, a.name, avg(s.price), avg(DATEDIFF(s.sold_date, m.enroll_date))\nfrom agent as a\njoin sold as s on a.agent_id = s.agent_id\njoin market as m on s.property_id = m.property_id\nwhere s.sale_date = 2022\ngroup by a.agent_id;");

                int state = 0;
                state = mysql_query(connection, query4);
                if (state == 0)
                {
                    sql_result = mysql_store_result(connection);
                    printf("\n%-30s %-30s %-30s %-30s\n", "Agent ID", "Name","Average Price","Average Date");
                    while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                    {
                        printf("%-30s %-30s %-30s %-30s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
                        break;
                    }
                    mysql_free_result(sql_result);
                    printf("\n");
                }
                
                while (1) {
                    printf("\n\n----- Subtypes in TYPE 4 -----\n");
                    printf("\t1. TYPE 4-1\n");
                    printf("\t2. TYPE 4-2\n");
    
                    int subcmd = 0;
                    printf(">    select a subquery type : ");
                    scanf("%d", &subcmd);

                    if (subcmd == 0) break;
                    else if (subcmd == 1) {
                        printf("**Compute the maximum selling price of properties sold in 2023 for each agent.\n");

                        char query4_1[1000] = { 0, };
                        sprintf(query4_1, "select a.agent_id, a.name, max(s.price)\nfrom agent as a\njoin sold as s on a.agent_id = s.agent_id\nwhere s.sale_date = 2023\ngroup by a.agent_id;");

                        int state = 0;
                        state = mysql_query(connection, query4_1);
                        if (state == 0)
                        {
                            sql_result = mysql_store_result(connection);
                            printf("\n%-30s %-30s %-30s\n", "Agent ID", "Name","Max Price");
                            while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                            {
                                printf("%-30s %-30s %-30s\n", sql_row[0], sql_row[1], sql_row[2]);
                                break;
                            }
                            mysql_free_result(sql_result);
                            printf("\n");
                        }
                    }
                    else if (subcmd == 2) {
                        printf("**Compute the longest time the property was on the market for each agent..\n");

                        char query4_2[1000] = { 0, };
                        sprintf(query4_2, "select a.agent_id, a.name, max(DATEDIFF(s.sold_date, m.enroll_date))\nfrom agent as a\njoin sold as s on a.agent_id = s.agent_id\njoin market as m on s.property_id = m.property_id\ngroup by a.agent_id;");

                        int state = 0;
                        state = mysql_query(connection, query4_2);
                        if (state == 0)
                        {
                            sql_result = mysql_store_result(connection);
                            printf("\n%-30s %-30s %-30s\n", "Agent ID", "Name","Max Date");
                            while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                            {
                                printf("%-30s %-30s %-30s\n", sql_row[0], sql_row[1], sql_row[2]);
                                break;
                            }
                            mysql_free_result(sql_result);
                            printf("\n");
                        }
                    }
                }
                
                
            }
            else if (command == 5) {
                while (1) {
                    printf("\n\n--- TYPE 5 ---\n\n");
                    printf("**Show photos of the most expensive studio, one-bedroom, multi-bedroom apartment(s), and detached house(s), respectively, from the database.\n");

                    char query5[1000] = { 0, };
                    sprintf(query5, "select m.id, m.name, m.type, m.photo\nfrom market as m\njoin(select m.type, max(price) as max_price\nfrom market as m\ngroup by m.type) as max_prices on m.type = max_prices.type and m.price = max_prices.max_price\nwhere m.type in ('studio', 'one-bedroom', 'multi-bedroom apartment(s)', 'detached house');");

                    int state = 0;
                    state = mysql_query(connection, query5);
                    if (state == 0)
                    {
                        sql_result = mysql_store_result(connection);
                        printf("\n%-30s %-30s %-30s %-30s\n", "Agent ID", "Name","Type", "Photo");
                        while ((sql_row = mysql_fetch_row(sql_result)) != NULL)
                        {
                            printf("%-30s %-30s %-30s %-30s\n", sql_row[0], sql_row[1], sql_row[2], sql_row[3]);
                            break;
                        }
                        mysql_free_result(sql_result);
                        printf("\n");
                    }
                }
            }
            else if (command == 6) {
                printf("\n\n--- TYPE 6 ---\n\n");
                printf("**Record the sale of a property that had been listed as being available. This entails storing the sales price, the buyer, the selling agent, the buyer’s agent(if any), and the date.\n");
                int price=0,id=0,date=0,school=0, bi=0, si=0, sai=0, bai=0;
                char name[50]={0,},address[100]={0,},type[20]={0,};
                printf("Enter according to the format\n");
                printf("Property (id) (price) (name) (address) (enroll_date) (school_district) (type)\n >> ");
                scanf("%d %d %s %s %s %s",&id, &price,name,address,&date, &school, type);
                printf("(buyer_id) (seller_id) (seller_agent_id) (buyer_agent_id)\n >> ");
                scanf("%d %d %d %d",&bi,&si,&sai,&bai);

                char query6[1000] = { 0, };
                sprintf(query6, "INSERT INTO sold (sold_id, price, name, address, sold_date, school_district, type)\nVALUES (%d, %d, %s, %s, %s, %s)\nINSERT INTO seller_sold (seller_id, sold_id)\nVALUES (%d, %d)\nINSERT INTO agent_sold (agent_id, sold_id, buy, sell)\nVALUES (%d, %d, 'O', 'X')\nINSERT INTO buyer_sold (buyer_id, sold_id)\nVALUES (%d, %d);",id,price,name,address,date,school,type,si,id,sai,id,bi,id);
                int state =0;
                state = mysql_query(connection, query6);
                if(state) printf("Insert Error!\n");
            }
            else if (command == 7) {
                printf("\n\n--- TYPE 7 ---\n\n");
                printf("**Add a new agent to the database.\n");
                printf("Enter according to the format[(id) (name) (address) (email) (phone num)]\n: ");
                int id=0;
                char name[50]={0,},address[100]={0,},email[100]={0,},phone[13]={0,};
                scanf("%d %s %s %s %s",&id,name,address,email,phone);

                char query7[1000] = { 0, };
                sprintf(query7,  "INSERT INTO agent (agent_id, name, address, email, phone_num)\nVALUES (%d, %s, %s, %s, %s);",id,name,address,email,phone);
                int state = 0;
                state = mysql_query(connection, query7);
                if(state) printf("Insert Error!\n");
            }
        }

        FILE* fp2;
        fp2 = fopen("20212022_2.txt", "r");
        while (!feof(fp2))
        {
            char data[1024];
            if (!fgets(data, 1024, fp2))
                break;
            mysql_query(connection, data);
        }
        fclose(fp2);

        printf("Bye");
    }

    return 0;
}
