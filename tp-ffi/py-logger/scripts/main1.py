import Logger as log
if __name__ == '__main__':

    print('TODO')
    logger = log.Logger()
    # TODO create a logger and add some items
    logger.add_item(log.Level.Info, "une info")
    logger.add_item(log.Level.Error, "une erreur")
    logger.add_item(log.Level.Info, "une autre info")
    logger.add_item(log.Level.Warning, "un avertissement")
    print(logger.report_by_added())
    print(logger.report_by_level())
    # TODO report_by_level

