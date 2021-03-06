TEST_TARGETS := cpp_common_test_test

cpp_common_test_test_SOURCES := accesslogger.cpp \
                                accumulator.cpp \
                                alarm.cpp \
                                alarmdefinition.cpp \
                                base64.cpp \
                                base_communication_monitor.cpp \
                                baseresolver.cpp \
                                cassandra_connection_pool.cpp \
                                cassandra_store.cpp \
                                chronosconnection.cpp \
                                communicationmonitor.cpp \
                                counter.cpp \
                                diameterresolver.cpp \
                                diameterstack.cpp \
                                dnscachedresolver.cpp \
                                dnsparser.cpp \
                                exception_handler.cpp \
                                health_checker.cpp \
                                http_connection_pool.cpp \
                                httpclient.cpp \
                                httpconnection.cpp \
                                a_record_resolver.cpp \
                                httpstack.cpp \
                                httpstack_utils.cpp \
                                json_alarms.cpp \
                                load_monitor.cpp \
                                localstore.cpp \
                                log.cpp \
                                logger.cpp \
                                memcached_config.cpp \
                                memcached_connection_pool.cpp \
                                memcachedstore.cpp \
                                memcachedstoreview.cpp \
                                namespace_hop.cpp \
                                realmmanager.cpp \
                                resolver_test.cpp \
                                saslogger.cpp \
                                signalhandler.cpp \
                                sip_string_to_request_type.cpp \
                                snmp_agent.cpp \
                                snmp_continuous_accumulator_table.cpp \
                                snmp_cx_counter_table.cpp \
                                snmp_event_accumulator_table.cpp \
                                snmp_infinite_base_table.cpp \
                                snmp_infinite_scalar_table.cpp \
                                snmp_infinite_timer_count_table.cpp \
                                snmp_row.cpp \
                                snmp_ip_row.cpp \
                                snmp_scalar.cpp \
                                snmp_single_count_by_node_type_table.cpp \
                                snmp_success_fail_count_table.cpp \
                                statistic.cpp \
                                timer_counter.cpp \
                                timer_heap.cpp \
                                unique.cpp \
                                utils.cpp \
                                zmq_lvc.cpp \
                                fakecurl.cpp \
                                fakehttpconnection.cpp \
                                fakelogger.cpp \
                                fakesnmp.cpp \
                                fakezmq.cpp \
                                mock_sas.cpp \
                                mockfreediameter.cpp \
                                pthread_cond_var_helper.cpp \
                                basetest.cpp \
                                curl_interposer.cpp \
                                test_main.cpp \
                                test_interposer.cpp \
                                alarm_test.cpp \
                                astaire_resolver.cpp \
                                baseresolver_test.cpp \
                                chronosconnection_test.cpp \
                                communicationmonitor_test.cpp \
                                connection_pool_test.cpp \
                                dnscachedresolver_test.cpp \
                                diameterresolver_test.cpp \
                                diameterstack_test.cpp \
                                httpclient_test.cpp \
                                httpconnection_test.cpp \
                                httpresolver_test.cpp \
                                httpstack_test.cpp \
                                httpstack_utils_test.cpp \
                                json_alarms_test.cpp \
                                load_monitor_test.cpp \
                                logger_test.cpp \
                                memcached_config_test.cpp \
                                memcachedstorereview_test.cpp \
                                realmmanager_test.cpp \
                                timer_heap_test.cpp \
                                utils_test.cpp \
                                bloom_filter.cpp \
                                siphash.cpp \
                                bloom_filter_test.cpp \
                                wildcard_utils.cpp \
                                wildcard_utils_test.cpp

cpp_common_test_test_CPPFLAGS := -Wno-write-strings \
                                 -I../usr/include \
                                 -I../modules/rapidjson/include \
                                 -I../modules/cpp-common/include \
                                 -Iut

cpp_common_test_test_LDFLAGS := -L../usr/lib \
                                -lthrift \
                                -lcassandra \
                                -lfdcore \
                                -lfdproto \
                                -lz \
                                -ldl \
                                -lpthread \
                                -lboost_regex \
                                -lzmq \
                                -lcares \
                                -levhtp \
                                -levent \
                                -levent_pthreads \
                                -lmemcached \
                                -lcurl \
                                `net-snmp-config --netsnmp-agent-libs`

COVERAGE_ROOT := ../modules/cpp-common/src

cpp_common_test_test_VALGRIND_ARGS := --suppressions=ut/cpp_common_test.supp

VPATH += ../modules/cpp-common/src ../modules/cpp-common/test_utils ut
include ../build-infra/cpp.mk

# Special extra objects for cpp_common_test
${BUILD_DIR}/bin/cpp_common_test_test : ${cpp_common_test_test_OBJECT_DIR}/test_interposer.so ${cpp_common_test_test_OBJECT_DIR}/curl_interposer.so

# Build rule for our interposer.
${cpp_common_test_test_OBJECT_DIR}/test_interposer.so : ../modules/cpp-common/test_utils/test_interposer.cpp ../modules/cpp-common/test_utils/test_interposer.hpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(cpp_common_test_test_CPPFLAGS) -shared -fPIC -ldl $< -o $@
CLEANS += ${cpp_common_test_test_OBJECT_DIR}/test_interposer.so

# Build rule for the CURL interposer.
${cpp_common_test_test_OBJECT_DIR}/curl_interposer.so : ../modules/cpp-common/test_utils/curl_interposer.cpp ../modules/cpp-common/test_utils/curl_interposer.hpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(cpp_common_test_test_CPPFLAGS) -shared -fPIC -ldl $< -o $@
CLEANS += ${cpp_common_test_test_OBJECT_DIR}/curl_interposer.so
